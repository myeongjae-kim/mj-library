#include <stdio.h>
#define MAX 4000000

void fib(int*, int*);

int main(int argc, const char *argv[])
{
	int fib1 = 1, fib2 = 1, sum = 0;

	while(fib2 <= MAX) {
		fib(&fib1, &fib2);
		sum += (fib2 % 2) == 0 ? fib2 : 0; // if fib2 has even number, add fib2 to the sum. if not, add zero to the sum.
	}

	printf("%d\n", sum);
	return 0;
}

void fib(int* fib1, int* fib2) {
	int temp = *fib2;

	*fib2 = *fib2 + *fib1;
	*fib1 = temp;
}
