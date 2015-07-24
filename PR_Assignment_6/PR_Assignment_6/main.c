#include <stdio.h>                  // for I/O
#include <stdlib.h>                 // for random # generator, malloc and free
#include <string.h>					// for string stuff

struct node
{
	char *name;
	double weight;
	struct node *next;
};

struct bin 
{
	double capacity;
	struct node *list;
};

struct node * insert(struct node *, char *, double);
void print(struct node *);
void destroy(struct bin *);

void main()
{
	struct bin bins[20];
	//char *names[] = { "Small dog", "Moose skull", "Squirrel", "Mouse", "Goldfish", "Snake", "Human finger", "Pig head","Eagle feather","Shark teeth","Camel hump","Crocodile","Elephant tusk","Cat","Horse manure","Monkey hand","Octopus eye","Sheep coat","Bat","Chicken wing" };
	//double weights[] = {0.63,0.25,0.41,0.15,0.06,0.52,0.09,0.39,0.02,0.11,0.24,0.94,0.63,0.28,0.04,0.21,0.05,0.33,0.42,0.12};
	//char *names[] = { "Vase", "Bowling ball", "Book", "Umbrella", "Gold Medal", "Speaker 1", "Walkman", "Speaker 2" };
	//double weights[] = { 0.5,0.9,0.3,0.4,0.7,0.4,0.2,0.4 };
	char *names[] = { "Operating Systems", "Computer Graphics", "The History of the Universe", "Discrete Mathematics", "Statistics", "English for Dummies", "American History 2000-", "Computer Architecture","C Programming","Hitchhikerís Guide","English-Minbari Dictionary","Zen and the Art of Programming","The Joy of Cooking","Cincinnati Yellow Pages","Artificial Intelligence","Business Programming: Why ?","Heart of Darkness","The History of the Ohio State Buckeyes" };
	double weights[] = {0.75,0.62,0.27,0.78,0.41,0.55,0.20,0.90,0.21,0.23,0.42,0.33,0.56,0.98,0.32,0.12,0.21,0.82};
	int n = sizeof(weights) / sizeof(weights[0]);
	int bn = sizeof(bins) / sizeof(bins[0]);
	struct bin *b;
	int count;
	for (int k = 0;k < bn;k++)
	{
		bins[k].list = NULL;
		bins[k].capacity = 1.0;
	}
	for (int i = 0;i < n;i++)
	{
		
		b = &bins[0];
		count = 0;
		while((b->capacity - weights[i] <= -0.001) && count < 20) 
		{
			count = count + 1;
			b = &bins[count];
		}
		b->capacity=b->capacity - weights[i];
		b->list = insert(b->list, names[i], weights[i]);	
	}
	for (int j = 0;j < bn;j++)
	{
		if (bins[j].list != NULL)
		{
			printf("\nbin %d: (%3.2f left)\n\n", j, bins[j].capacity);
			print(bins[j].list);
			destroy(&bins[j]);
		}
	}
}

struct node * insert(struct node * front, char *name, double weight)
{
	struct node *item, *current, *previous;
	item = (struct node *)malloc(sizeof(struct node));
	item->name = name;
	item->weight = weight;
	item->next = NULL;
	if (front == NULL)
	{
		return item;
	}
	else if (strcmp(item->name, front->name) <= 0)
	{
		item->next = front;
		return item;
	}
	else
	{
		current = front;
		previous = NULL;
		while (current != NULL && strcmp(current->name, item->name) <= 0) {
			previous = current;
			current = current->next;
		}
		previous->next = item;
		item->next = current;
		return front;
	}
}

void print(struct node * front)
{
	while (front != NULL)		// while we still have nodes in the list
	{                
		printf("\t%s: (%3.2f)\n", front->name, front->weight);    // print data item
		front = front->next;              // move onto next node
	}
}

void destroy(struct bin * b)
{
	struct node *front = b->list;
	struct node *temp;          // points to current node to be deallocated
	while (front != NULL)		// while still nodes in the list
	{        
		temp = front;             // point at current node
		front = front->next;      // move front pointer to next node
		free(temp);             // dispose of current node
	}
	b->list = NULL;
	b->capacity = 1.0;
}


/*
Run 1:

	bin 0: (0.00 left)

		Eagle feather: (0.02)
		Goldfish: (0.06)
		Horse manure: (0.04)
		Moose skull: (0.25)
		Small dog: (0.63)

	bin 1: (0.00 left)

		Camel hump: (0.24)
		Human finger: (0.09)
		Mouse: (0.15)
		Shark teeth: (0.11)
		Squirrel: (0.41)

	bin 2: (0.04 left)

		Octopus eye: (0.05)
		Pig head: (0.39)
		Snake: (0.52)

	bin 3: (0.06 left)

		Crocodile: (0.94)

	bin 4: (0.09 left)

		Cat: (0.28)
		Elephant tusk: (0.63)

	bin 5: (0.04 left)

		Bat: (0.42)
		Monkey hand: (0.21)
		Sheep coat: (0.33)

	bin 6: (0.88 left)

		Chicken wing: (0.12)

Run 2:

	bin 0: (0.05 left)

		American History 2000-: (0.20)
		Operating Systems: (0.75)

	bin 1: (0.11 left)

		Computer Graphics: (0.62)
		The History of the Universe: (0.27)

	bin 2: (0.01 left)

		C Programming: (0.21)
		Discrete Mathematics: (0.78)

	bin 3: (0.04 left)

		English for Dummies: (0.55)
		Statistics: (0.41)

	bin 4: (0.10 left)

		Computer Architecture: (0.90)

	bin 5: (0.02 left)

		English-Minbari Dictionary: (0.42)
		Hitchhiker∆s Guide: (0.23)
		Zen and the Art of Programming: (0.33)

	bin 6: (0.00 left)

		Artificial Intelligence: (0.32)
		Business Programming: Why ?: (0.12)
		The Joy of Cooking: (0.56)

	bin 7: (0.02 left)

		Cincinnati Yellow Pages: (0.98)

	bin 8: (0.79 left)

		Heart of Darkness: (0.21)

	bin 9: (0.18 left)

		The History of the Ohio State Buckeyes: (0.82)

*/