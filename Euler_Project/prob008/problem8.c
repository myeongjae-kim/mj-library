#include <stdio.h>
#include <stdlib.h>

#define MEM 1
#define FIL 2
#define ARG 1

int idxcounter = 0;

long getMaxProduct(int* ary, int idx);
void PrintAry(int* ary, int idx);
void EIN(void* adr, int messageselector); // Error If Null
// messageselector: 0 or any number -> default, 1 or MEM -> memory, 2or FIL -> file.

void EIF(int integer, int messageselector); // Error If False
// messageselector: 0 or any number -> default, 1 or ARG-> argument.

void freeN(void** adr); // free() and insert NULL value to the pointer.
// The argument should be address of pointer variable.

int main(int argc, char const *argv[])
{
    FILE* fp;
    int count = 0, *ary, i;
    long max;
    
    EIN(fp = fopen("input_8.txt", "r"), FIL);
    while(!feof(fp))
    {
        if(fgetc(fp) != '\n') count++;
    }
    count--;
    fclose(fp);
    EIN(fp = fopen("input_8.txt", "r"), FIL);
    EIN(ary = calloc(count, sizeof(int)), MEM);
    for (i = 0; i < count; i++) {
        ary[i] = fgetc(fp);
        if(ary[i] == '\n' || ary[i] == EOF) {
            i--;
            continue;
        }
        ary[i] -= '0';
    }
    PrintAry(ary, count);
    
    max = getMaxProduct(ary, count);
    printf("\n%ld\n", max);
    printf("count:%d\n", count);
    printf("%d\n", idxcounter);
    
    freeN((void**)&ary);
    fclose(fp);
    return 0;
}

long getMaxProduct(int* ary, int idx)
{
    int i, j;
    long result, max = 0;
    for (i = 0; i <= idx - 13; i++) {
        result = 1;
        for (j = i; j < i + 13; j++) {
            result *= ary[j];
        }
        if ( result > max) {
            max = result;
            idxcounter = i;
        }
    }
    return max;
}

void PrintAry(int* ary, int idx)
{
    int i;
    for (i = 0; i < idx; i++) {
        printf("%d", ary[i]);
        if( (i + 1) % 50 == 0 ) printf("\n");
    }
    putchar('\n');
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


