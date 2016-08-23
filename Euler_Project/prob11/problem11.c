#include <stdio.h>
#include <stdlib.h>

#define MEM 1
#define FIL 2
#define ARG 1

void printData(int ary[][20]);
void insertData(FILE* fp, int ary[][20]);
int getMaxProduct(int ary[][20]);
int hrzMaxProduct(int ary[][20]);
int vtcMaxProduct(int ary[][20]);
int rightdiagMaxProduct(int ary[][20]);
int leftdiagMaxProduct(int ary[][20]);
void EIN(void* adr, int messageselector); // Error If Null
// messageselector: 0 or any number -> default, 1 or MEM -> memory, 2or FIL -> file.

void EIF(int integer, int messageselector); // Error If False
// messageselector: 0 or any number -> default, 1 or ARG-> argument.

void freeN(void** adr); // free() and insert NULL value to the pointer.
// The argument should be address of pointer variable.

int main(int argc, char const *argv[])
{
   int ary[20][20], max;
   FILE* fp;

   EIN(fp = fopen("pb11.txt", "r"), FIL);
   
   insertData(fp, ary);
   printData(ary);
   printf("max product: %d\n", max = getMaxProduct(ary));
   fclose(fp);
   return 0;
}

int getMaxProduct(int ary[][20])
{
	int hrzMax = 0;
	int vtcMax = 0;
	int rightdiagMax = 0;
	int leftdiagMax = 0;
	
	hrzMax = hrzMaxProduct(ary);
	vtcMax = vtcMaxProduct(ary);
	hrzMax = hrzMax > vtcMax ? hrzMax : vtcMax;

	rightdiagMax = rightdiagMaxProduct(ary);
	leftdiagMax = leftdiagMaxProduct(ary);
	rightdiagMax = rightdiagMax > leftdiagMax ? rightdiagMax : leftdiagMax;

	return rightdiagMax > hrzMax ? rightdiagMax : hrzMax; 
}
int hrzMaxProduct(int ary[][20])
{
	int max = 0, result = 0;
	int i, j, k;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 17; j++) {
			result = 1;
			for (k = j; k < j + 4; k++) {
				result *= ary[i][k];
			}
			max = result > max ? result : max;
		}
	}
	return max;
}
int vtcMaxProduct(int ary[][20])
{
	int max = 0, result = 0;
	int i, j, k;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 17; j++) {
			result = 1;
			for (k = j; k < j + 4; k++) {
				result *= ary[k][i];
			}
			max = result > max ? result : max;
		}
	}
	return max;

}
int rightdiagMaxProduct(int ary[][20])
{	
	int max = 0, result = 0;
	int i, j, k;
	for (i = 0; i < 17; i++) {
		for (j = 0; j < 17; j++) {
			result = 1;
			for (k = j; k < j + 4; k++) {
				result *= ary[k][i + k - j];
			}
			max = result > max ? result : max;
		}
	}
	return max;

}
int leftdiagMaxProduct(int ary[][20])
{
	int max = 0, result = 0;
	int i, j, k;
	for (i = 3; i < 20; i++) {
		for (j = 0; j < 17; j++) {
			result = 1;
			for (k = j; k < j + 4; k++) {
				result *= ary[i + j - k][k];
			}
			max = result > max ? result : max;
		}
	}
	return max;

}
void insertData(FILE* fp, int ary[][20])
{
	int i, j;

	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			fscanf(fp, "%d", &ary[i][j]);
		}
	}
}
void printData(int ary[][20])
{
	int i, j;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++) {
			printf( "%d ", ary[i][j]);
		}
		putchar('\n');
	}
}
void EIN(void* adr, int messageselector) // Error If Null
{       // messageselector: 0 or any number -> default, 1 -> memory, 2 -> file.
    if(!adr)
    {
	switch (messageselector) {
	    case 1:
		printf("Memory cannot be allocated!\n");
		break;
		
	    case 2:
		printf("File Opening Error!\n");
		break;
		
	    default:
		printf("Null Address Error!\n");
		break;
	}
	exit(-1);
    }
}

void EIF(int integer, int messageselector) // Error If FALSE
{       // messageselector: 0 or any number -> default, 1-> argument.
    if(!integer)
    {
	switch (messageselector) {
	    case 1:
		printf("Command line argument error!\n");
		printf("Usage: [executive file]\n");
		break;
		
	    default:
		printf("FALSE! FALSE!\n");
		break;
	}
	exit(-1);
    }
}

void freeN(void** adr) {
    if(!(*adr)) {
	printf("freeN(): The variable has NULL value. It cannot be free\n");
	return;
    }
    free(*adr);
    *adr = NULL;
}
