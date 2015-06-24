#include <c:\users\perrye1.perry\documents\githubvisualstudio\csc362\pr_assignment_2\PR_Assignment_2\prototypes.h> 

void main(){
	char in_file[] = "grades1.txt";			// the input file
	char out_file[] = "output.txt";
	FILE *fp_in, *fp_out;						// fp1 points to the input file, fp2 points to the output file
	int file_length;
	int i, hi, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec, total_students, total_passing, total_failing, num_params;
	double average, total_average;
	char first_name[20], last_name[20], letter_grade;

	fp_in = fopen(in_file, "r");
	fp_out = fopen(out_file, "w");

	fscanf(fp_in, "%d", &file_length);
	for (i=0;i < file_length;i++) 
	{
		num_params = inputLine(fp_in, first_name, last_name, &hi, &h2, &h3, &h4, &p1, &p2, &p3, &p4, &p5, &p6, &m1, &m2, &m3, &ec);
		if (num_params = 16)
		{
			computeGrade(hi, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec, &average, &letter_grade);
			outputLine(first_name, last_name, average, letter_grade);
			update(&total_students, &total_average, &total_passing, &total_failing);
		}
		else
		{
			fprintf(fp_out, "Error attempting to read line %d, skipping record", i);
		}
		
	}
	summarize(total_students, total_average, total_passing, total_failing);
}