#pragma once
#include<stdio.h>

int inputLine(FILE *fp_in, char *first_name, char *last_name, int *hi, int *h2, int *h3, int *h4, int *p1, int *p2, int *p3, int *p4, int *p5, int *p6, int *m1, int *m2, int *m3, int *ec);
void computeGrade(int hi, int h2, int h3, int h4, int p1, int p2, int p3, int p4, int p5, int p6, int m1, int m2, int m3, int ec, double *average, char *letter_grade);
void outputLine(char first_name, char last_name, double average, char leter_grade);
void update(int *total_students, double *total_average, int *total_passing, int *total_failing);
void summarize(int total_students, double total_average, int total_passing, int total_failing);