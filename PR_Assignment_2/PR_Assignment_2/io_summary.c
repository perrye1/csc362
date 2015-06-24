#include<c:\users\perrye1.perry\documents\githubvisualstudio\csc362\pr_assignment_2\PR_Assignment_2\prototypes.h>

int inputLine(FILE *fp_in, char *first_name, char *last_name, int *h1, int *h2, int *h3, int *h4, int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *m1, int *m2, int *m3, int *ec)
{
	//TODO: input data
}
void outputLine(FILE *fp_out, char first_name, char last_name, double average, char leter_grade)
{
	fprintf(fp_out, "Student: %s %s has average of %4.2d%% and grade of %s", first_name, last_name, average, leter_grade);
}
void summarize(FILE *fp_out, int total_students, double total_average, int total_passing, int total_failing)
{
	fprintf(fp_out, "Of %d students, the average grade is %4.2d%%\n", total_students, total_average/total_students);
	fprintf(fp_out, "The number of students passing is %d\n", total_passing);
	fprintf(fp_out, "The number of students failing is %d\n", total_failing);
}