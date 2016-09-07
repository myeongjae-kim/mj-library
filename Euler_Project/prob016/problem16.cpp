#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    vector<char> strBuff;
    char iBuff = 0;

    strBuff.push_back(1);
    
    for (int i = 1; i <= 1000; i++) {
        int carry = 0;
        for (int j = 0; j < strBuff.size(); j++) {
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
            strBuff.push_back(carry);

        for(auto i = strBuff.rbegin(); i != strBuff.rend(); i++) {
            printf("%d", *i);
        }
        cout << endl;
    }
    
    int answer = 0;
    for (auto i : strBuff) {
        answer += i;
    }
    
    printf("Answer: %d\n", answer);
    
    return 0;
}
