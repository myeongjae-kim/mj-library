#include <iostream>
#include <string>
#include <vector>
#include "mjUtil.h"
using namespace std;

vector<string> returnNamesInFile(FILE* fp);
int sumOfCharacters(const string str);

int main(int argc, const char *argv[])
{
    ARG_CHECK(2);

    FILE* fp = nullptr;
    FOPEN(fp, argv[1], "r");

    vector<string> &&names = returnNamesInFile(fp);
    sort(names.begin(), names.end());

    int sizeOfNames = names.size();
    long answer = 0;
    for (int i = 0; i < sizeOfNames; i++) {
        answer += (i + 1) * sumOfCharacters(names[i]);
    }
    
    std::cout << "Answer: "<< answer << std::endl;

    return 0;
}

vector<string> returnNamesInFile(FILE* fp) {
    string strBuff;
    vector<string> rtString;

    while( !feof(fp) ) {
        char cbuff = fgetc(fp);
        if(isalpha(cbuff)) {
            do {
                strBuff += cbuff;
                cbuff = fgetc(fp);
            }while(isalpha(cbuff));
            rtString.push_back(strBuff);
            strBuff.clear();
        }
    }

    return rtString;
}

int sumOfCharacters(const string str) {
    int sum = 0;
    for(auto i = str.rbegin(); i != str.rend(); i++) {
        sum += (*i) - 'A' + 1;
    }
    return sum;
}
