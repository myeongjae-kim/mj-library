#include <stdio.h>

int IsPrime(int number);
int main(int argc, const char *argv[])
{
	int count = 1, i;
	long sumofprime = 0;

	for (i = 3; i <= 2000000 ; i++) {
		if( IsPrime(i) == 1) {
			count++;
			sumofprime += i;
			printf("%d\n", i);
		}
	}
	printf("%ld\n", sumofprime + 2);
	return 0;
}

int IsPrime(int number)
{
	int i;
	for (i = 2; i < number / 2 + 1; i++) {
		if(number % i == 0) return 0;
	}
	return 1;
}
