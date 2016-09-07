#include <iostream>
#include <vector>
#include "mjUtil.h"
#include <algorithm>
using namespace std;

#define STRSIZE 512
#define NUMSIZE 3

void readIntegerFromFile(FILE* fp, vector< vector<int> > &numbers);

int main(int argc, const char *argv[])
{
    ARG_CHECK(2);

    FILE *fp = nullptr;
    FOPEN(fp, argv[1], "r");

    vector< vector<int> > numbers;
    
    readIntegerFromFile(fp, numbers);

    //Priting input file.
    /* for (auto &v : numbers) {
     *     for (auto &vv : v) {
     *         cout << vv << " ";
     *     }
     *     cout << endl;
     * }  */

    vector< vector<int> > answers;
    vector<int> answerBuff;

    answers.push_back(answerBuff); // line matching with numbers.

    // below is for first case.
    answerBuff.push_back(numbers[0][0] + numbers[1][0]);
    answerBuff.push_back(numbers[0][0] + numbers[1][1]);
    answers.push_back(answerBuff);
    answerBuff.clear(); 
    
    // complete the dynamic programming table.
    for (int i = 1; i < numbers.size() - 1; i++) {
        for (int j = 0; j < numbers[i].size(); j++) {
            int sumBuff1 = 0;
            int sumBuff2 = 0;

            sumBuff1 = answers[i][j] + numbers[i + 1][j];
            sumBuff2 = answers[i][j] + numbers[i + 1][j + 1];

            if(j == 0)
                answerBuff.push_back(sumBuff1);
            else {
                answerBuff[j] = answerBuff[j] > sumBuff1 ? answerBuff[j] : sumBuff1;
            }
            answerBuff.push_back(sumBuff2);
        }
        answers.push_back(answerBuff);
        answerBuff.clear();
    }

    //Priting dynamic programming table
    /* for (auto &v : answers) {
     *     for (auto &vv : v) {
     *         cout << vv << " ";
     *     }
     *     cout << endl;
     * }   */

    vector<int> &lastVector = *(answers.end() - 1);

    int maxSum = *max_element(lastVector.begin(), lastVector.end());
    std::cout << "Answer: "<< maxSum << std::endl;

    return 0;
}
void readIntegerFromFile(FILE* fp, vector< vector<int> > &numbers) {
    vector<int> buff;

    char strBuff[STRSIZE] = {0};
    char numBuff[NUMSIZE] = {0};
    int strBuffIdx = 0;
    int numBuffIdx = 0;

    int iBuff = 0;
    
    while(fgets(strBuff, STRSIZE, fp) != nullptr) {
        while(strBuff[strBuffIdx] != 0) {
            while(strBuff[strBuffIdx] != ' ' && strBuff[strBuffIdx] != 0) {
                // read integer and write it to numBuff
                numBuff[numBuffIdx] = strBuff[strBuffIdx];
                numBuffIdx++;
                strBuffIdx++;
            }
            // insert ibuff to buff
            iBuff = atoi(numBuff);
            buff.push_back(iBuff);
            iBuff = 0;
            
            memset(numBuff, 0, NUMSIZE);
            numBuffIdx = 0;

            strBuffIdx++;
        }

        // insert buff to numbers
        strBuffIdx = 0;
        memset(strBuff, 0, STRSIZE);
        numbers.push_back(buff);
        buff.clear();
    }
}
