#include<prototypes.h>

int inputLine(FILE *fp_in, char *first_name, char *last_name, int *h1, int *h2, int *h3, int *h4, int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *m1, int *m2, int *m3, int *ec)
{
	int num;
	num = fscanf(fp_in,"%s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d", first_name, last_name, h1,h2,h3,h4,p1,p2,p3,p4,p5,p6,m1,m2,m3,ec);
	return num;
}
void outputLine(FILE *fp_out, char *first_name, char *last_name, double average)
{
	char letter_grade[2];
	if (average >= 90) 
	{
		strcpy(letter_grade,"A");
	}
	else if(average <= 89 && average >= 80)
	{
		strcpy(letter_grade, "B");
	}
	else if (average <= 79 && average >= 70)
	{
		strcpy(letter_grade, "C");
	}
	else if (average <= 69 && average >= 60)
	{
		strcpy(letter_grade, "D");
	}
	else if (average <= 59)
	{
		strcpy(letter_grade, "F");
	}
	fprintf(fp_out,"Student: %s %s has average of %4.2f%% and grade of %s\n", first_name, last_name, average, letter_grade);
}
void summarize(FILE *fp_out, int total_students, double total_average, int total_passing, int total_failing)
{
	fprintf(fp_out, "Of %d students, the average grade is %4.2d%%\n", total_students, total_average/total_students);
	fprintf(fp_out, "The number of students passing is %d\n", total_passing);
	fprintf(fp_out, "The number of students failing is %d\n", total_failing);
}