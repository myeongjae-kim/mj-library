#include <stdio.h>
#include "mjCUtil.h"

int main(int argc, const char *argv[])
{
    int *a;
    int x = 10, y = 30, temp = 0;
    FILE* fp;
    bool varBoolean = true;

    if ( varBoolean == true) {
        printf("\tvarBoolean is true\n");
        varBoolean = false;
    }
    if ( varBoolean == false) {
        printf("\tvarBoolean is false\n");
    }


    printf("\tx = %d, y = %d\n", x, y);
    printf("\tSWAP(x, y, temp)\n");
    SWAP(x, y, temp);
    printf("\tx = %d, y = %d\n", x, y);

    MALLOC(a, sizeof(*a));
    FREE(a);
    CALLOC(a, 1, sizeof(*a));
    REALLOC(a, 4);
    FREE(a);
    FREE(a);
    FOPEN(fp, argv[1], "r");
    fclose(fp);



    return 0;
}
