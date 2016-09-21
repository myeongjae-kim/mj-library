#include <iostream>

#define ROWCOL 1001
// #define ROWCOL 5

void printMatrix(int matrix[ROWCOL][ROWCOL]);
void fillTheMatrix(int matrix[ROWCOL][ROWCOL]);
int returnAnswer(int matrix[ROWCOL][ROWCOL]);

int main(int argc, const char *argv[])
{
    int matrix[ROWCOL][ROWCOL] = {0};
    
    fillTheMatrix(matrix);
    // printMatrix(matrix);

    printf("Answer : %d\n", returnAnswer(matrix));
    
    return 0;
}

void printMatrix(int matrix[ROWCOL][ROWCOL]) {
    for (int i = 0; i < ROWCOL; i++) {
        for (int j = 0; j < ROWCOL; j++) {
            printf("%4d ", matrix[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void fillTheMatrix(int matrix[ROWCOL][ROWCOL]) {
    int i = ROWCOL / 2;
    int j = ROWCOL / 2;
    int nToBeWritten = 1;
    int k = 1;
    int temp = 0;
    bool matrixCompleted = false;

    matrix[i][j] = nToBeWritten++;

    while(1) {
        // east
        for (temp = 0; temp < k; temp++) {
            j++;
            matrix[i][j] = nToBeWritten++;

            if(nToBeWritten - 1 == ROWCOL * ROWCOL) {
                matrixCompleted = true;
                break;
            }
        }

        if(matrixCompleted) break;

        // south
        for (temp = 0; temp < k; temp++) {
            i++;
            matrix[i][j] = nToBeWritten++;
        }

        k++;

        // west
        for (temp = 0; temp < k; temp++) {
            j--;
            matrix[i][j] = nToBeWritten++;
        }

        // north
        for (temp = 0; temp < k; temp++) {
            i--;
            matrix[i][j] = nToBeWritten++;
        }

        k++;
    }   
}

int returnAnswer(int matrix[ROWCOL][ROWCOL]) {
    int k = 0;
    int sum = 0;

    while(k != ROWCOL / 2) {
        sum += matrix[k][k];
        sum += matrix[ROWCOL - 1 - k][k];
        sum += matrix[k][ROWCOL - 1 - k];
        sum += matrix[ROWCOL - 1 - k][ROWCOL - 1 - k];
        k++;
    }

    sum += matrix[k][k];
    return sum;
}
