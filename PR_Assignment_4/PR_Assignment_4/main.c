#include <stdio.h>

void main() {
	int sum = 0;
	int result = 0;
	int input = 0;
	__asm {
		top:		mov eax, 0
	}
	printf("Enter the next input : ");
	scanf("%d", &input);
	__asm {
					// code here to determine whether to exit (if input == 0) or continue

		begin:		mov	eax, input
					cmp	eax, 0
					je	xout
					cmp	eax, sum
					jg	primeTest

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

		isPrime:	mov eax, input
					mov ebx, sum
					cmp ebx, eax
					jge notAdd
					add ebx, input
					mov sum, ebx
					mov result, 0
					jmp top

		notAdd :	mov result, 1
					jmp xout

		notPrime:	mov result, 2
					jmp xout

		xout :		nop
	}
	if (result == 0) printf("Correct sequence\n");
	else if (result == 1) printf("Sequence not increasingly additive\n");
	else printf("Sequence contains non - prime \n");
}

