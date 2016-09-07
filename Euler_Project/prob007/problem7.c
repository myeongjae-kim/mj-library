#include <stdio.h>

int IsPrime(int number);
int main(int argc, const char *argv[])
{
	int count = 1, i;

	for (i = 3; count < 10001 ; i++) {
		if( IsPrime(i) == 1) {
			count++;
			printf("%d\n", i);
		}
	}
	return 0;
}

int IsPrime(int number)
{
	int i;
	for (i = 2; i < number; i++) {
		if(number % i == 0) return 0;
	}
	return 1;
}
