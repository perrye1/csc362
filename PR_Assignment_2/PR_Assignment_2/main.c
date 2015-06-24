#include <prototypes.h> 

void main(){
	char in_file[] = "grades1.txt";			// the input file
	char out_file[] = "output.txt";
	FILE *fp_in;
	FILE *fp_out;						// fp1 points to the input file, fp2 points to the output file
	int file_length;
	int i, h1, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec, total_students, total_passing, total_failing, num_params;
	double average, total_average;
	char first_name[20];
	char last_name[20];

	fp_in = fopen(in_file, "r");
	fp_out = fopen(out_file, "w");

	fscanf(fp_in, "%d", &file_length);
	for (i=0;i < file_length;i++) 
	{
		num_params = inputLine(fp_in, first_name, last_name, &h1, &h2, &h3, &h4, &p1, &p2, &p3, &p4, &p5, &p6, &m1, &m2, &m3, &ec);
		if (num_params == 16)
		{
			computeGrade(h1, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec, &average);
			outputLine(fp_out, first_name, last_name, average);
			update(average, &total_students, &total_average, &total_passing, &total_failing);
		}
		else
		{
			fprintf(fp_out, "Error attempting to read line %d, skipping record\n", i+1);
		}
		
	}
	summarize(fp_out, total_students, total_average, total_passing, total_failing);
}