// NAME:	Ethan Perry
// CLASS:	CSC362
// DUE:		7/8/15

// This programs plays the game of "Chutes and Ladders"

#include<stdio.h>
#include<time.h>

void printBoard(FILE *fp_out, char *a, char *p1, char *p2);		// print the board after every turn, showing the changes
int move(char *p, char *p_opp, char *board);					// moves the player through the board
int find_haven(char *p, char *board);							// finds the next haven on the board, either forward or backward

void main() 
{
	srand(time(NULL));											// seed for the random number generator
	char out_file[] = "output.txt";								// the output file
	FILE *fp_out;												// output file pointer
	fp_out = fopen(out_file, "a");								// open the output file to write
	char board[100] = "  mHk nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB ";
	char *p1 = board;											// pointer for player 1
	char *p2 = board;											// pointer for player 2
	while (1)
	{
		printf("player 1: ");										
		p1=move(p1, p2, board);									// call the move function on player 1, also passing player 2 so we can check for collisions
		if (p1 >= board + 100)									// if the player pointer is pointing at the end of the board, that player has won
		{
			printf("Player 1 has won the game\n");
			break;
		}
		printf("player 2: ");
		p2=move(p2, p1, board);									// call the move function on player 1, also passing player 2 so we can check for collisions
		if (p2 >= board + 100)									// if the player pointer is pointing at the end of the board, that player has won
		{
			printf("Player 2 has won the game\n");
			break;
		}
		printBoard(fp_out, board, p1, p2);						// calls the printBoard function after every turn
	}	
}

int move(char *p, char *p_opp, char *board)						// moves the player through the board
{
	int dice_roll = rand() % 6 + 1;
	p=p+dice_roll;
	printf("rolled %d...",dice_roll);
	if (p >= board && p < board + 100)
	{
		if (p == p_opp)
		{
			printf("collision...moving back %d...", 1);
			p = p - 1;
		}
		else if (*p == 'B' || *p == 'F')
		{
			p += find_haven(p, board);
		}
		else if(*p <= 122 && *p >= 97 && *p != 110)
		{
			int sub_move = (int)(*p - 110);
			if (sub_move < 0)
			{
				printf("landed on a chute...moving %d...", sub_move);
			}
			else
			{
				printf("landed on a ladder...moving %d...", sub_move);
			}
			*p = '*';
			p = p + sub_move;
		}
	}
	if (p == p_opp)
	{
		printf("collision...moving back %d...", 1);
		p = p - 1;
	}
	printf("now at %d\n",p-board);
	return p;
}

void printBoard(FILE *fp_out, char *a, char *p1, char *p2)	// print the board after every turn, showing the changes
{
	while (*a != '\0')										// while we haven't hit the end of the string
	{
		if (a == p1)
		{
			putc('1', fp_out);								// if the current character is where the player 1 is, print a 1
		}
		else if (a == p2)
		{
			putc('2', fp_out);								// if the current character is where the player 2 is, print a 2
		}
		else 
		{
			putc(*a, fp_out);								// print the current character
		}
		a++;												// move on to the next character of a
	}
	putc('\n', fp_out);										// go to the next line
}

int find_haven(char *p, char *board)						// finds the next haven on the board, either forward or backward
{
	int count = 0;
	if (*p == 'B')
	{
		while (*p != 'H' && p != board)
		{
			p = p - 1;
			count = count - 1;
		}
		printf("moving backward to haven...");
		if (p == board)
		{
			printf("no havens left...");
		}
		else 
		{
			*p = '_';
		}
	}
	else 
	{
		while (*p != 'H' && p != board + 100)
		{
			p = p + 1;
			count = count + 1;
		}
		printf("moving forward to haven...");
		if (p == board+100)
		{
			printf("no havens left...");
			count = 0;
		}
		else
		{
			*p = '_';
		}
	}
	return count;
}