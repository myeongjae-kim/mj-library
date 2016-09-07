#include <iostream>

int main(int argc, const char *argv[])
{
	long n = 600851475143, largestPrimeFactor = 0;
	int i = 0;

	for (i = 2; i <= n; i++) {
		if( n % i == 0)
		{
			n /= i;
			largestPrimeFactor = i;
			printf("n = %ld, i = %d, largestPrimeFactor = %ld\n", n, i, largestPrimeFactor);
		}
	}
	return 0;
}
