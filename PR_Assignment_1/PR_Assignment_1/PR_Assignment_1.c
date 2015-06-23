//NAME:		Ethan Perry
//CLASS:	CSC362
//DUE:		6/9/15

//This program takes in an input file, reads it, and outputs the characters to an ouput file based on the given pattern.
//It also provides as summary, listing the names of the files, the number of input and output characters, and the percent reduction.

#include <stdio.h>							// for file functions
#include <ctype.h>

int main()
{
	char c;									// holds the current character
	char last_alpha;						// holds the last character that is a letter
	char in_file[] = "input3.txt";			// the input file
	char out_file[] = "output1.txt";		// the output file
	int cap_flag = 1;						// flag to determine if a capital letter should be ouput (after a period) 
	int in_count =0;						// counter for the number of input letters
	int out_count =  0;						// counter for the number of output letters
	FILE *fp1, *fp2;						// fp1 points to the input file, fp2 points to the output file
	fp1 = fopen(in_file, "r");				// open input file, read-only
	fp2 = fopen(out_file, "w");				// open output file, write-only

	while ((c = getc(fp1)) != -1)           // get next char from input file, store in x, until we reach EOF
	{
		in_count++;							// increment the input count
		if (isalpha(c))
		{
			if (isupper(c))
			{
				if (cap_flag == 1)
				{
					putc(c, fp2);			
					out_count++;
					cap_flag = 0;			// if c is an upercase letter, and the cap_flag = 1 , output the character to the output file ad increment the output count. 
				}
				else if (islower(last_alpha))
				{
					putc(tolower(c), fp2);
					out_count++;			// if c is an upercase letter, the cap_flag != 1 , and the last letter was lowercase, output the lowercase value of the character to the output file and increment the output count. 
				}
			}
			else
			{
				if (isupper(last_alpha))
				{
					putc(c, fp2);
					out_count++;			// if c is a lowercase letter, and the last letter was uppercase , output the character to the output file and increment the output count. 
				}
			}
			last_alpha = c;					// if c is a letter, set the last letter variable to the current character
		}
		else
		{
			putc(c, fp2);
			out_count++;					// if c is not a letter, output it and increment the output count
			if (c == '.')
			{
				cap_flag = 1;				// if c is a period, the next uppercase letter should be output as uppercase, so set the cap_flag
			}
		}

	}

	//the output statements, that will print out the filenames, number of input and output characters, and percent reduction
	//The percent reduction is rounded to 2 decimal places. 

	printf("Input File: %s\n", in_file);
	printf("Output File: %s\n", out_file);
	printf("Number of input characters: %d\n", in_count);
	printf("Number of output characters: %d\n", out_count);
	printf("Percent reduction in output: %.2f%%\n", 100*((double)out_count/in_count));
}

