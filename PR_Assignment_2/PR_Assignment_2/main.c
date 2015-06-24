#include <C:\Users\perrye1.PERRY\Documents\GitHubVisualStudio\csc362\PR_Assignment_2\PR_Assignment_2\prototypes.h> 

void main(){
	char in_file[] = "grades1.txt";			// the input file
	char out_file[] = "output.txt";
	FILE *fp_in, *fp_out;						// fp1 points to the input file, fp2 points to the output file
	int file_length;
	int i, hi, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec;
	char first_name[20], last_name[20];

	fp_in = fopen(in_file, "r");
	fp_out = fopen(out_file, "w");

	fscanf(fp_in, "%d", &file_length);
	for (i=0;i < file_length;i++) 
	{

	}
}