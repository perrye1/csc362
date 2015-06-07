#include <stdio.h>                      // for file functions
#include <ctype.h>

int main()
{
	char c;
	char last_alpha;
	char in_file[] = "input1.txt";
	char out_file[] = "output1.txt";
	int cap_flag = 1;
	int in_count =0;
	int out_count =  0;
	FILE *fp1, *fp2;		            // fp1 points to the input file, fp2 points to the output file
	fp1 = fopen(in_file, "r");	    // open input file, read-only
	fp2 = fopen(out_file, "w");	// open output file, write-only

	while ((c = getc(fp1)) != -1)            // get next char from input file, store in x, until we reach EOF
	{
		in_count++;
		if (isalpha(c))
		{
			if (isupper(c))
			{
				if (cap_flag == 1)
				{
					putc(c, fp2);                   // output the character to the output file
					out_count++;
					cap_flag = 0;
				}
				else if (islower(last_alpha))
				{
					putc(tolower(c), fp2);
					out_count++;
				}
			}
			else
			{
				if (isupper(last_alpha))
				{
					putc(c, fp2);
					out_count++;
				}
			}
			last_alpha = c;
		}
		else
		{
			putc(c, fp2);
			out_count++;
			if (c == '.')
			{
				cap_flag = 1;
			}
		}

	}

	printf("Input File: %s\n", in_file);
	printf("Output File: %s\n", out_file);
	printf("Number of input characters: %d\n", in_count);
	printf("Number of output characters: %d\n", out_count);
	printf("Percent reduction in output: %.2f%%\n", 100*((double)out_count/in_count));
}

