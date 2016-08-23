#include <iostream>
#include <cmath>

int main(int argc, const char *argv[])
{
	long n = 600851475143;
    long largestPrimeFactor = 0;
    long maxFactor = 0;
	int i = 0;

    printf("n: %ld\n", n);

    // when n is even number
    if(n % 2 == 0)
    {
        n /= 2;
        largestPrimeFactor = 2;

        while(n % 2 == 0)
            n /= 2;
    }
    else
        largestPrimeFactor = 1;

    // now, n is odd number. so we can increase i with 2;
    maxFactor = sqrt(n);
	for (i = 3; n > 1 && i <= maxFactor; i = i + 2) {
		if( n % i == 0)
		{
			n /= i;
			largestPrimeFactor = i;

            while(n % i == 0)
                n /= i;
            
            maxFactor = sqrt(n);
		}
	}

    // print the answer.
    printf("Largest Prime Factor: ");
    if( n == 1 )
        printf("%ld\n", largestPrimeFactor);
    else
        printf("%ld\n", n);

	return 0;
}
