#include <iostream>
#include <string>
#include <vector>
#include "mjUtil.h"

#define STRSIZE 51

using namespace std;

int main(int argc, const char *argv[])
{
    ARG_CHECK(2);

    vector<string> numbers;
    FILE* fp = nullptr;

    FOPEN(fp, argv[1], "r");

    char* strBuff = new char[STRSIZE];

    int ibuff = 0;
    while(ibuff = fscanf(fp, "%s", strBuff)) {
        numbers.PB(strBuff);
        memset(strBuff, '\0', STRSIZE);
    }

    for (auto s : numbers) {
        std::cout << s << std::endl;
    }

    delete[] strBuff;
    return 0;
}
