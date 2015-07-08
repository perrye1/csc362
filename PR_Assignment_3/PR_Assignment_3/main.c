// NAME:	Ethan Perry
// CLASS:	CSC362
// DUE:		7/8/15

// This programs plays the game of "Chutes and Ladders"

#include<stdio.h>
#include<time.h>

void printBoard(FILE *fp_out, char *a, char *p1, char *p2);		// print the board after every turn, showing the changes
int move(char *p, char *p_opp, char *board);					// moves the player through the board
int findHaven(char *p, char *board);							// finds the next haven on the board, either forward or backward

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
	int dice_roll = rand() % 6 + 1;								// simulate a dice roll
	p=p+dice_roll;
	printf("rolled %d...",dice_roll);
	if (p >= board && p < board + 100)							// make sure the player is still on the board
	{
		if (p == p_opp)											// check if there is a collision between players
		{
			printf("collision...moving back %d...", 1);
			p = p - 1;
		}
		else if (*p == 'B' || *p == 'F')						// check if the player has landed on a "go to haven" square
		{
			p += findHaven(p, board);							// call the findHaven function to find the nearest haven in the correct direction
		}
		else if(*p <= 122 && *p >= 97 && *p != 110)				// check if the player has landed on a chute or a ladder
		{
			int sub_move = (int)(*p - 110);						// subtract the asci value of the chute or ladder symbol to determine how far to move
			if (sub_move < 0)
			{
				printf("landed on a chute...moving %d...", sub_move);
			}
			else
			{
				printf("landed on a ladder...moving %d...", sub_move);
			}
			*p = '*';											// "remove" the chute or ladder by replacing it with an *
			p = p + sub_move;
		}
	}
	if (p == p_opp)												// check again for a collision, after we have moved the player
	{
		printf("collision...moving back %d...", 1);
		p = p - 1;
	}
	printf("now at %d\n",p-board);
	return p;
}

void printBoard(FILE *fp_out, char *a, char *p1, char *p2)		// print the board after every turn, showing the changes
{
	while (*a != '\0')											// while we haven't hit the end of the string
	{
		if (a == p1)
		{
			putc('1', fp_out);									// if the current character is where the player 1 is, print a 1
		}
		else if (a == p2)
		{
			putc('2', fp_out);									// if the current character is where the player 2 is, print a 2
		}
		else 
		{
			putc(*a, fp_out);									// print the current character
		}
		a++;													// move on to the next character of a
	}
	putc('\n', fp_out);											// go to the next line
}

int findHaven(char *p, char *board)								// finds the next haven on the board, either forward or backward
{
	int count = 0;
	if (*p == 'B')												// check if this is a directive to move forward or backward to a haven
	{
		while (*p != 'H' && p != board)							// make sure we are staying on the board
		{
			p = p - 1;
			count = count - 1;
		}
		printf("moving backward to haven...");
		if (p == board)											// if we are at the beginning of the board, there must not have been any havens left, so we go to zero
		{
			printf("no havens left...");
		}
		else													// if we did find a haven, remove it so it cant be used again
		{
			*p = '_';
		}
	}
	else 
	{
		while (*p != 'H' && p != board + 100)					// make sure we are staying on the board
		{
			p = p + 1;
			count = count + 1;
		}
		printf("moving forward to haven...");
		if (p == board+100)										// if we are at the end of the board, there must not have been any havens left, so we stay where we were
		{
			printf("no havens left...");
			count = 0;
		}
		else
		{
			*p = '_';											// if we did find a haven, remove it so it cant be used again
		}
	}
	return count;
}

/*

OUTPUT TO TERMINAL:

player 1: rolled 3...now at 3
player 2: rolled 1...now at 1
player 1: rolled 4...now at 7
player 2: rolled 3...landed on a chute...moving -3...now at 1
player 1: rolled 2...landed on a chute...moving -2...now at 7
player 2: rolled 1...landed on a chute...moving -1...now at 1
player 1: rolled 5...now at 12
player 2: rolled 3...now at 4
player 1: rolled 5...landed on a chute...moving -2...now at 15
player 2: rolled 4...now at 8
player 1: rolled 2...now at 17
player 2: rolled 3...moving backward to haven...now at 7
player 1: rolled 4...now at 21
player 2: rolled 1...now at 8
player 1: rolled 1...now at 22
player 2: rolled 6...landed on a chute...moving -9...now at 5
player 1: rolled 4...moving backward to haven...now at 22
player 2: rolled 3...now at 8
player 1: rolled 1...now at 23
player 2: rolled 2...now at 10
player 1: rolled 3...moving backward to haven...now at 13
player 2: rolled 5...now at 15
player 1: rolled 5...landed on a ladder...moving 3...now at 21
player 2: rolled 4...now at 19
player 1: rolled 4...landed on a chute...moving -6...collision...moving back 1...now at 18
player 2: rolled 2...now at 21
player 1: rolled 6...now at 24
player 2: rolled 1...now at 22
player 1: rolled 1...now at 25
player 2: rolled 1...now at 23
player 1: rolled 4...landed on a chute...moving -2...now at 27
player 2: rolled 4...collision...moving back 1...now at 26
player 1: rolled 4...landed on a ladder...moving 1...now at 32
player 2: rolled 3...now at 29
player 1: rolled 3...moving backward to haven...now at 33
player 2: rolled 1...landed on a chute...moving -6...now at 24
player 1: rolled 2...moving backward to haven...now at 28
player 2: rolled 2...moving backward to haven...now at 3
player 1: rolled 4...now at 32
player 2: rolled 3...now at 6
player 1: rolled 1...now at 33
player 2: rolled 2...now at 8
player 1: rolled 6...landed on a ladder...moving 4...now at 43
player 2: rolled 2...now at 10
player 1: rolled 5...landed on a chute...moving -4...now at 44
player 2: rolled 4...now at 14
player 1: rolled 5...now at 49
player 2: rolled 3...now at 17
player 1: rolled 6...landed on a chute...moving -3...now at 52
player 2: rolled 4...now at 21
player 1: rolled 3...now at 55
player 2: rolled 4...now at 25
player 1: rolled 5...now at 60
player 2: rolled 4...now at 29
player 1: rolled 3...now at 63
player 2: rolled 6...moving backward to haven...no havens left...now at 0
player 1: rolled 6...now at 69
player 2: rolled 1...now at 1
player 1: rolled 6...moving forward to haven...now at 79
player 2: rolled 2...now at 3
player 1: rolled 1...now at 80
player 2: rolled 2...now at 5
player 1: rolled 5...moving backward to haven...now at 69
player 2: rolled 3...now at 8
player 1: rolled 3...now at 72
player 2: rolled 3...moving backward to haven...no havens left...now at 0
player 1: rolled 6...now at 78
player 2: rolled 4...now at 4
player 1: rolled 4...landed on a chute...moving -1...now at 81
player 2: rolled 4...now at 8
player 1: rolled 5...now at 86
player 2: rolled 5...now at 13
player 1: rolled 6...landed on a chute...moving -6...now at 86
player 2: rolled 1...now at 14
player 1: rolled 2...landed on a chute...moving -2...now at 86
player 2: rolled 5...now at 19
player 1: rolled 6...now at 92
player 2: rolled 3...now at 22
player 1: rolled 2...now at 94
player 2: rolled 3...now at 25
player 1: rolled 6...now at 100
Player 1 has won the game

OUTPUT TO FILE:

 2m1k nH l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
 2mH* n1 l B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
 2*H* n1 * B He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H2 nH * B1He Flq p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* nH2* B He1F*q p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n2 * B He F1q p H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_2* B He F*q p1H  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H*2n_ * B H* F*q p 1  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_2* B H* F*q p 1  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ *2B H* F*q p _1 hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B 1*2F*q p _  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F**2p1_  hByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F*1 p2_  *ByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F** p 2 1*ByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F** p _2 1ByHlho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F** p _  *21H*ho H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F** p _  *ByH2h*1H B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *H* n_ * B _* F** p _ 2*ByH*** 1 B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *2* n_ * B _* F** p _  *By1*** _ B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* 2_ * B _* F** p _  *By_***1_ B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_2* B _* F** p _  *By_*** 1 B  jr HFB ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_ *2B _* F** p _  *By_*** _ B  j* HF1 ir j H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_ * B _2 F** p _  *By_*** _ B  j* HFB1ir * H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_ * B _* F2* p _  *By_*** _ B  j* HFB ir *1H  F ku gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_ * B _* F** p2_  *By_*** _ B  j* HFB ir * H 1F *u gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_ * B _* F** p _  2By_*** _ B  j* HFB ir * H  F 1u gd  H pjB mH x  BF i H  m oB HlHFBhoH BB
  *_* n_ * B _* F** p _  *By_2** _ B  j* HFB ir * H  F *u gd1 H pjB mH x  BF i H  m oB HlHFBhoH BB
2 *_* n_ * B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H1pjB mH x  BF i H  m oB HlHFBhoH BB
 2*_* n_ * B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m1 x  BF i H  m oB HlHFBhoH BB
  *2* n_ * B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB mH x  BF i 1  m oB HlHFBhoH BB
  *_*2n_ * B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB mH x  BF i _1 m oB HlHFBhoH BB
  *_* n_2* B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m1 x  BF i _  m oB HlHFBhoH BB
2 *_* n_ * B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x1 BF i _  m oB HlHFBhoH BB
  *_2 n_ * B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i1_  m oB HlHFBhoH BB
  *_* n_2* B _* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i _ 1* oB HlHFBhoH BB
  *_* n_ * B 2* F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i _  * oB1HlHFBhoH BB
  *_* n_ * B _2 F** p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i _  * oB1HlHFB*oH BB
  *_* n_ * B _* F**2p _  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i _  * oB1H*HFB*oH BB
  *_* n_ * B _* F** p 2  *By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i _  * oB H*HFB1oH BB
  *_* n_ * B _* F** p _  2By_*** _ B  j* HFB ir * H  F *u gd  H pjB m_ x  BF i _  * oB H*HFB*o1 BB

*/