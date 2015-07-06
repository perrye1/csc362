// NAME:	Ethan Perry
// CLASS:	CSC362
// DUE:		6/25/15
// FILE:	main.c

// This program takes in an input file containing student's individual grades, and outputs a list of the student's averages and letter grades
// It also provides a summary, listing the overall class average, and number of students that passed/failed. 

#include <prototypes.h>						// include the header file that contains the function declarations and constants 

void main(){
	char in_file[] = "grades2.txt";			// the input file
	char out_file[] = "output2.txt";			// the output file
	FILE *fp_in;							// fp_in points to the input file
	FILE *fp_out;							// fp_out points to the output file
	int file_length;						// stores the length of the file (lines)
	int i, h1, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec, num_params;		//ints for the grades, an iterator, and the number of params returned by the inputLine function
	int total_students=0;					// stores the total number of students read in
	int total_passing=0;					// stores the total number of passing students
	int total_failing=0;					// stores the total number of failing students
	double average=0.0;						// stores the average for each individual student
	double total_average=0.0;				// stores the overall average of the class
	char first_name[20];					// stores the students first name
	char last_name[20];						// stores the students last name
	char letter_grade[2];					// stores the students letter grade

	fp_in = fopen(in_file, "r");			// open the input file to read
	fp_out = fopen(out_file, "w");			// open the output file to write

	fscanf(fp_in, "%d", &file_length);		// get the first number in the file, which will be the length in lines
	for (i=0;i < file_length;i++)			// iterate for each line
	{
		num_params = inputLine(fp_in, first_name, last_name, &h1, &h2, &h3, &h4, &p1, &p2, &p3, &p4, &p5, &p6, &m1, &m2, &m3, &ec);		// input the line and store the number of paramaters successfuly read
		if (num_params == 16)																					// if the number of parameters is 16, continue, else print out an error
		{
			computeGrade(h1, h2, h3, h4, p1, p2, p3, p4, p5, p6, m1, m2, m3, ec, &average, letter_grade);		// computes the students average and letter grade
			outputLine(fp_out, first_name, last_name, average, letter_grade);									// writes a line to the output file
			update(average, &total_students, &total_average, &total_passing, &total_failing, letter_grade);		// updates the overall average, and pass/fail counters
		}
		else
		{
			fprintf(fp_out, "Error attempting to read line %d, skipping record\n", i+1);						// the error message to write out to the file if a line cant be read
		}
		
	}
	summarize(fp_out, total_students, total_average, total_passing, total_failing);								// writes out a summary statement to the end of the output file, with the overall average, and pass/fail numbers
	fclose(fp_in);																								// close the input file
	fclose(fp_out);																								// close the output file
}