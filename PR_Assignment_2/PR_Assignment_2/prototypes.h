#include<stdio.h>			// for standard input output operations like scanf, printf, fscanf, and fprintf
#include<string.h>			// for string operations like strcpy and strcmp

#define WEIGHT1 .25			// grade weights defined as constants
#define WEIGHT2 .25
#define WEIGHT3 .5

// the function prototypes for this project
int inputLine(FILE *fp_in, char *first_name, char *last_name, int *h1, int *h2, int *h3, int *h4, int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *m1, int *m2, int *m3, int *ec);
void computeGrade(int h1, int h2, int h3, int h4, int p1, int p2, int p3, int p4, int p5, int p6, int m1, int m2, int m3, int ec, double *average, char *letter_grade);
void outputLine(FILE *fp_out, char *first_name, char *last_name, double average, char *letter_grade);
void update(double average, int *total_students, double *total_average, int *total_passing, int *total_failing, char *letter_grade);
void summarize(FILE *fp_out, int total_students, double total_average, int total_passing, int total_failing);