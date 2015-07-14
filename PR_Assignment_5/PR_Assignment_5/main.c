#include <stdio.h>

void main()
{
	int a[] = { 100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12 };
	int n = 20;
	int i = 1;
	int temp = 0;
	int location = 0;

	__asm {

				mov ebx, i				// set ebx to i
				mov eax, 0
		floop:	mov ecx, n				// reset ecx to n every time
				cmp ebx, ecx			// compare i to n
				jge fout				// if i is greater than or equal to n, jump out of the for loop

				mov eax, a[ebx]			// store the array value in eax (as temp)
				mov edx, ebx			// reset location to i
				dec edx					// decrement the location by one

		wloop:	cmp edx, 0				// compare the location to 0
				jge wcase2				// if the location is greater than or equal to 0, jump to evaluate the next case of the while 
				jmp wout				// if the first condition is false, we can short circuit and jump out of the while loop			

		wcase2: cmp a[edx], eax			// compare the value of a at the stored location to temp
				jg wtrue				// if a[location] is greater than temp, the while loop conditions are true, so jump to wtrue

		wtrue:	mov ecx, edx			// we can temporarily use ecx to store location since ecx gets reset every time at the beginning of the loop
				inc edx					// increment the location
				mov ecx, a[ecx]			// set ecx to the value at the old location in a
				mov a[edx], ecx			// set the value in a at the incremented location to the old location
				sub edx, 2				// decrement the location back to where it was
				jmp wloop				// jump back to the top of the while loop

		wout:	inc ebx					// increment i by one
				inc edx					// increment the location by one
				mov a[edx], eax			// store temp in a at the incremented location 
				jmp floop				// jump back up to the top of the for loop
		fout:	nop	

	}

	for (i = 1;i < n;i++)
	{
		printf("%d,", a[i]);
	}

}




