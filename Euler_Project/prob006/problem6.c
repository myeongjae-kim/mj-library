#include <stdio.h>
#include <stdlib.h>

int SumOfSquares(int targetnum);
int SquareOfSum(int targetnum);
int main(int argc, const char *argv[])
{
	int difference;
	
	difference = SquareOfSum(100) - SumOfSquares(100);
	printf("%d\n", difference);
	return 0;
}

int SumOfSquares(int targetnum)
{
	int result = 0, i;
	for (i = 1; i <= targetnum; i++) {
		result += i * i;
	}
	return result;
}

int SquareOfSum(int targetnum)
{
	int result = 0, i;
	for (i = 1; i <= targetnum; i++) {
		result += i;
	}
	return result * result;
}
