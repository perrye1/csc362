#pragma once
#include<stdio.h>
#define WEIGHT1 .25
#define WEIGHT2 .25
#define WEIGHT3 .5

int inputLine(FILE *fp_in, char *first_name, char *last_name, int *h1, int *h2, int *h3, int *h4, int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *m1, int *m2, int *m3, int *ec);
void computeGrade(int h1, int h2, int h3, int h4, int p1, int p2, int p3, int p4, int p5, int p6, int m1, int m2, int m3, int ec, double *average, char *letter_grade);
void outputLine(FILE *fp_out, char first_name, char last_name, double average, char leter_grade);
void update(int average, int *total_students, double *total_average, int *total_passing, int *total_failing);
void summarize(FILE *fp_out, int total_students, double total_average, int total_passing, int total_failing);