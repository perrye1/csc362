// NAME:	Ethan Perry
// CLASS:	CSC362
// DUE:		7/8/15

// This programs plays the game of "Chutes and Ladders"

#include<stdio.h>
#include<time.h>
void printBoard(FILE *fp_out, char *a);		// print the string character by character using pointer arithmetic
int move(char *p, char *board, int turn);

void main() 
{
	srand(time(NULL));
	char out_file[] = "output.txt";			// the output file
	FILE *fp_out;							// output file pointer
	fp_out = fopen(out_file, "a");			// open the output file to write
	char board[100] = "  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";	char *p1 = board;
	char *p2 = board;
	while (p1 < board + 100 && p2 < board + 100)
	{
		p1=move(p1, board, 1);
		p2=move(p2, board, 2);
		//printBoard(fp_out, board);
	}
	if (p1 >= board + 100)
	{
		printf("Player 1 has won the game");
	}
	else if (p2 >= board + 100)
	{
		printf("Player 2 has won the game");
	}
	
}

int move(char *p, char *board, int turn)
{
	int dice_roll = rand() % 6 + 1;
	p=p+dice_roll;
	if (p > board && p < board + 100)
	{
		if (*p == 'B' || *p == 'F')
		{
			p += find_haven(*p);
			return p;
		}
		else
		{
			p = p + (int)(*p - 110);
		}
	}
	else
	{
		return p;
	}
}

void printBoard(FILE *fp_out, char *a)	// print the string pointed to by a
{
	while (*a != '\0')		// while we haven't hit the end of the string
	{
		putc(*a, fp_out);	// print the current character
		a++;		// move on to the next character of a
	}
	putc('\n', fp_out);
}

int find_haven(char h)
{
	if (h == 'B')
	{

	}
}