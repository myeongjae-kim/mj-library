#include <iostream>
#include <string>
#include <vector>
#include "mjUtil.h"

#define NUMBERSIZE 50
#define STRSIZE NUMBERSIZE + 1

using namespace std;

void getNumbersFromFile(FILE* fp, vector<string> &numbers);

int main(int argc, const char *argv[])
{
    ARG_CHECK(2);

    vector<string> numbers;
    FILE* fp = nullptr;

    FOPEN(fp, argv[1], "r");


    for (auto s : numbers) {
        std::cout << s << std::endl;
    }

    return 0;
}

void getNumbersFromFile(FILE* fp, vector<string> &numbers)
{
    char* strBuff = new char[STRSIZE];

    while(fscanf(fp, "%s", strBuff) != EOF) {
        numbers.PB(strBuff);
        memset(strBuff, '\0', STRSIZE);
    }

    delete[] strBuff;
    return;
}
