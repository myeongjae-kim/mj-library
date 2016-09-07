#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    int buffSize = 2;
    int* strBuff = (int*)calloc(buffSize, sizeof(int));
    
    int i = 0, j = 0;
    int iBuff = 0;
    int strSize = 1;

    int answer = 0;

    strBuff[0] = 1;
    
    for (i = 1; i <= 1000; i++) {
        int carry = 0;
        for (j = 0; j < strSize; j++) {
            if(carry)
                iBuff = strBuff[j] * 2 + carry;
            else {
                iBuff = strBuff[j] + carry;
                iBuff *= 2;
            }
            
            strBuff[j] = iBuff % 10;
            carry = iBuff / 10;
        }
        if(carry)
        {
            if(strSize + 1 >= buffSize)
            {
                buffSize *= 2;
                strBuff = (int*)realloc(strBuff, sizeof(int) * buffSize);
            }
            strBuff[strSize++] = carry;
        }
        for (j = strSize - 1; j >= 0; j--) {
            printf("%d", strBuff[j]);
        }
        putchar('\n');
    }
    
    for (j = strSize - 1; j >= 0; j--) {
        answer += strBuff[j];
    }
    
    printf("Answer: %d\n", answer);
    
    free(strBuff);
    return 0;
}
