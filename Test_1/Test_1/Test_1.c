#include <stdio.h>                      // for file functions
#include <ctype.h>

int main()
{
	char c;
	char last_alpha;
	int cap_flag = 1;
	FILE *fp1, *fp2;		            // fp1 points to the input file, fp2 points to the output file
	fp1 = fopen("input3.txt", "r");	    // open input file, read-only
	fp2 = fopen("output1.txt", "w");	// open output file, write-only

	while ((c = getc(fp1)) != -1)            // get next char from input file, store in x, until we reach EOF
	{
		if (isalpha(c))
		{
			if (isupper(c))
			{
				if (cap_flag == 1)
				{
					putc(c, fp2);                   // output the character to the output file
					cap_flag = 0;
				}
				else if (islower(last_alpha))
				{
					putc(tolower(c), fp2);
				}
			}
			else
			{
				if (isupper(last_alpha))
				{
					putc(c, fp2);
				}
			}
			last_alpha = c;
		}
		else
		{
			putc(c, fp2);
			if (c == '.')
			{
				cap_flag = 1;
			}
		}

	}
}

