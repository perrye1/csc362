#include <stdio.h>

void main() {
	int sum = 0;						// holds the sume
	int result = 0;						// holds the result flag
	int input = 0;						// holds the current input number
	__asm {
		top:		mov eax, 0			// clear the eax every iteration of the loop
	}
	printf("Enter the next input : ");
	scanf("%d", &input);
	__asm {
					// code here to determine whether to exit (if input == 0) or continue

		begin:		mov	eax, input		// load input into the eax
					cmp	eax, 0			// compare input to 0
					je	xout			// if input is 0, jump out

					// code to determine if input is prime 

		primeTest:	mov ebx, 2			// put i in the ebx (loop counter)
		xloop:		mov eax, input		// reset eax to n on every loop
					cmp ebx, eax		// compare eax to ebx
					jge isPrime			// if we made it through without the remainder ever equaling zero, the number must be prime, jump to the true bit
					mov edx, 0			// else clear the remainder register
					div ebx				// divide eax by ebx
					cmp edx, 0			// compare the remainder to zero
					je notPrime			// if the remainder is zero, our number is not prime, jump to the false bit
					add ebx, 1			// else increment the loop counter
					jmp xloop			// go to the top of the loop

					// code to determine if input is increasingly additive

		isPrime:	mov eax, input		// move input to the eax to get ready to compare to sum
					mov ebx, sum		// move sum to the ebx
					cmp eax, ebx		// compare the input and the sum
					jle notAdd			// if the input is less than or equal to the sum, the series is not additive
					add ebx, input		// else, add the input to the sum
					mov sum, ebx		// store the sum
					mov result, 0		// set the result to 0 (good result)
					jmp top				// jump to the top of the loop

		notAdd :	mov result, 1		// if the series is not additive, set the result to 1 and jump out
					jmp xout

		notPrime:	mov result, 2		// if the series is not prime, set the result to 2 and jump out
					jmp xout

		xout :		nop					// how we break out of the loop
	}
	if (result == 0) printf("Correct sequence\n");
	else if (result == 1) printf("Sequence not increasingly additive\n");
	else printf("Sequence contains non-prime \n");
}

