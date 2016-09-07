#include <iostream>
#include <string>
#include <vector>
#include "mjUtil.h"

#define NUMBERSIZE 50
#define STRSIZE NUMBERSIZE + 1

using namespace std;

void getNumbersFromFile(FILE* fp, vector<string> &numbers);
string calculateNumbers(vector<string> &numbers);

int main(int argc, const char *argv[])
{
    ARG_CHECK(2);

    vector<string> numbers;
    FILE* fp = nullptr;

    FOPEN(fp, argv[1], "r");

    getNumbersFromFile(fp, numbers);

    string reversedAnswer = calculateNumbers(numbers);
    for (auto rbegin = reversedAnswer.rbegin(); rbegin != reversedAnswer.rend(); rbegin++) {
        cout << rbegin;
    }
    cout << endl;



    fclose(fp);
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

string calculateNumbers(vector<string> &numbers)
{
    string strBuff;
    int iBuff = 0;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < NUMBERSIZE; j++) {
            iBuff += numbers[j][i] - '0';
            strBuff.PB( (iBuff % 10) + '0' );
            iBuff /= 10;
        }
    }
    
    return strBuff;
}
