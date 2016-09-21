#include <stdio.h>
#define MAX 4000000

void fib(int*, int*, int*);

int main(int argc, const char *argv[])
{
	int fib1 = 1, fib2 = 1, fib3 = fib1 + fib2, sum = 0;

	while(fib3 <= MAX) {
		sum += fib3; 
		fib(&fib1, &fib2, &fib3);
	}

	printf("%d\n", sum);
	return 0;
}

void fib(int* fib1, int* fib2, int* fib3) {
	*fib1 = *fib3 + *fib2;
	*fib2 = *fib1 + *fib3;
	*fib3 = *fib2 + *fib1;	
}
