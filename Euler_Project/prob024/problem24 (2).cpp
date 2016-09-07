#include <stdio.h>
#include <stdlib.h>

#include <vector>
#include <string>

using namespace std;

#define MEM 1
#define FIL 2
#define ARG 1

#define MAX_CHARACTER 100

void EIN(void* adr, int messageselector); // Error If Null
// messageselector: 0 or any number -> default, 1 or MEM -> memory, 2or FIL -> file.

void EIF(int integer, int messageselector); // Error If False
// messageselector: 0 or any number -> default, 1 or ARG-> argument.

void freeN(void** adr); // free() and insert NULL value to the pointer.
// The argument should be address of pointer variable.

void perm(char *list, int i, int n, FILE* fp);
void swap(char* a, char* b);

vector<string> perms;
string strBuff;

int main(int argc, char const *argv[])
{
    int n, i;
    char* list;
    FILE* fp;

    EIF(argc == 3, ARG); // if argc is not 3, exit program.
    EIN(fp = fopen(argv[1], "r"), FIL); // if NULL value inserted, exit program.
    EIN(list = (char*)malloc(sizeof(char) * MAX_CHARACTER), MEM);
    
    /* scanning argv[1] */
    for (i = 0; i < MAX_CHARACTER; ++i)
    {
        list[i] = fgetc(fp);
        if(list[i] == '{' || list[i] == ',') i--; // If it is not an alphabet, rewriting. 
        if(list[i] == '}') break;
    }
    fclose(fp);
    /* argv[1] scanning end */

    /* start printing to argv[2] */
    EIN(fp = fopen(argv[2], "w"), FIL);
    
    printf("=== Permutation! ===\n");
    perm(list, 0, i-1, fp);
    
    fclose(fp);
    /* printing end */
    freeN((void**)&list);

    cout << "Sorting ..." << endl;
    sort(perms.begin(), perms.end());

    cout << perms[1000000] endl;
    
    return 0;
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
                printf("Usage: [executive file] [input.txt] [output.txt]\n");
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
        printf("freeN(): The variable has NULL value. It cannot be freed.\n");
        return;
    }
    free(*adr);
    *adr = NULL;
}

void perm(char *list, int i, int n, FILE* fp)
{
    int j = 0;
    if( i == n) {    /* recursion failure. Print a permutation */
        for (j = 0; j <= n; ++j) {
            // fprintf(fp, "%c", list[j]);
            strBuff += list[j];
        }
        // fputc('\n', fp);
        perms.push_back(strBuff);
        strBuff.clear();
    }
    
    else {    /* recursion success. Reduce problem size and re-call perm() */
        for (j = i; j <= n; ++j)
        {
            swap(&list[i], &list[j]);
            perm(list, i + 1, n, fp);
            swap(&list[i], &list[j]);
        }
    }
}

void swap(char* a, char* b) {
    char temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}
