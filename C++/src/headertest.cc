#include <iostream>
#include <stdio.h>
#include "mjUtil.h"
#include "isPrime.h"

using namespace std;

int main(int argc, const char *argv[])
{
	int *a;
	int x = 10, y = 30;
	FILE* fp;

	printf("\tx = %d, y = %d\n", x, y);
	printf("\tSWAP(x, y, temp)\n");
	swap(x, y);
	printf("\tx = %d, y = %d\n", x, y);

    a = (int*)malloc(sizeof(*a));
	FREE(a);
    a = (int*)calloc(1, sizeof(*a));
    a = (int*)realloc(a, sizeof(*a));
	FREE(a);
	FREE(a);

    cout << "\n\t 7 is Prime? " << isPrime(7) << endl << endl;

	FOPEN(fp, argv[1], "r");
	fclose(fp);

	return 0;
}
