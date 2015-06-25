#include<prototypes.h>		// include the header file that contains the function declarations and constants

// computes the student's letter grade and average based on the individual scores, and the WEIGHT constants
void computeGrade(int h1, int h2, int h3, int h4, int p1, int p2, int p3, int p4, int p5, int p6, int m1, int m2, int m3, int ec, double *average, char *letter_grade)
{
	*average = ((((h1 + h2 + h3 + h4) / 4.0)*WEIGHT1) + (((p1 + p2 + p3 + p4 + p5 + p6) / 6.0)*WEIGHT2) + (((m1 + m2 + m3 + ec) / 3.0)*WEIGHT3));

	if ((*average <= 59) || (m1<=30 || m2<=30 || m3<=30))		// if the student recieved a 30 or below on any test, they auto-fail the class
	{
		strcpy(letter_grade, "F");
	}
	else if (*average <= 69 && *average >= 60)
	{
		strcpy(letter_grade, "D");
	}
	else if (*average <= 79 && *average >= 70)
	{
		strcpy(letter_grade, "C");
	}
	else if (*average <= 89 && *average >= 80)
	{
		strcpy(letter_grade, "B");
	}
	else if (*average >= 90)
	{
		strcpy(letter_grade, "A");
	}
}

// keeps track of the total number of students, overall class average, and pass/fail numbers
void update(double average, int *total_students, double *total_average, int *total_passing, int *total_failing, char *letter_grade)
{
	*total_students+=1;
	printf("%d", *total_students);
	*total_average = *total_average + average;
	if (strcmp(letter_grade, "F"))			// since a student can have a passing average, but still fail the class (see function computeGrade), we need to update the pass/fail numbers using the letter grades instead of the averages
	{
		*total_passing += 1;
	}
	else
	{
		*total_failing += 1;
	}
}