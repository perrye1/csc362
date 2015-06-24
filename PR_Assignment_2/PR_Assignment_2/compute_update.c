#include<prototypes.h>

void computeGrade(int h1, int h2, int h3, int h4, int p1, int p2, int p3, int p4, int p5, int p6, int m1, int m2, int m3, int ec, double *average)
{
	*average = ((((h1 + h2 + h3 + h4) / 4.0)*WEIGHT1) + (((p1 + p2 + p3 + p4 + p5 + p6) / 6.0)*WEIGHT2) + (((m1 + m2 + m3 + ec) / 3.0)*WEIGHT3));
}
void update(double average, int *total_students, double *total_average, int *total_passing, int *total_failing)
{
	*total_students++;
	*total_average = *total_average + average;
	if (average <= 65)
	{
		*total_failing++;
	}
	else
	{
		*total_passing++;
	}
}