#include<stdio.h>
	int n = 20;
{
	int a[] = { 100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12 };
	int n = 20;
	for (int i = 1;i<n;i++)
	{
		int temp = a[i];
		int location = i - 1;
		while (location >= 0 && a[location]>temp) {
			a[location + 1] = a[location];
			location--;
		}
		a[location + 1] = temp;
	}