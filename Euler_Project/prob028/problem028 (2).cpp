#include <iostream>

// #define ROWCOL 1001
#define ROWCOL 5

void printMatrix(int matrix[ROWCOL][ROWCOL]);

int main(int argc, const char *argv[])
{
    int matrix[ROWCOL][ROWCOL] = {0};
    int i = ROWCOL / 2;
    int j = ROWCOL / 2;
    int nToBeWritten = 1;
    int k = 1;
    int temp = 0;

    matrix[i][j] = nToBeWritten++;

    while(1) {
        // east
        for (temp = 0; temp < k; temp++) {
            j++;
            matrix[i][j] = nToBeWritten++;
        }

        printMatrix(matrix);

        if(nToBeWritten - 1 == ROWCOL * ROWCOL) break;

        // south
        for (temp = 0; temp < k; temp++) {
            i++;
            matrix[i][j] = nToBeWritten++;
        }
        printMatrix(matrix);

        k++;

        // west
        for (temp = 0; temp < k; temp++) {
            j--;
            matrix[i][j] = nToBeWritten++;
        }
        printMatrix(matrix);

        // north
        for (temp = 0; temp < k; temp++) {
            i--;
            matrix[i][j] = nToBeWritten++;
        }
        printMatrix(matrix);

        k++;
    }


    
    return 0;
}
void printMatrix(int matrix[ROWCOL][ROWCOL]) {
    for (int i = 0; i < ROWCOL; i++) {
        for (int j = 0; j < ROWCOL; j++) {
            printf("%4d ", matrix[i][j]);
        }
        putchar('\n');
    }
}
