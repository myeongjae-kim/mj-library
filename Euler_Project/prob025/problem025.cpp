#include <iostream>
#include <vector>
using namespace std;

vector<int> strSum(vector<int> &num1, vector<int> &num2);
void printNumber(const vector<int> &num);
void fib(vector<int> &num1, vector<int> &num2, vector<int> &num3);

int main(int argc, const char *argv[])
{
    vector<int> num1;
    vector<int> num2;
    vector<int> num3;

    num1.push_back(1);
    num2.push_back(1);
    num3 = strSum(num1, num2);

    int fibIdxOfNum3 = 3;

    while(num3.size() != 1000) {
        fib(num1, num2, num3);
        fibIdxOfNum3++;
    }

    std::cout << "Answer: " << fibIdxOfNum3 << std::endl;
    return 0;
}

vector<int> strSum(vector<int> &num1, vector<int> &num2) {
    vector<int> sum;
    int carry = 0;
    int num1Size = num1.size();
    int num2Size = num2.size();
    int i = 0;

    if(num1Size > num2Size) {
        for (i = 0; i < num2Size; i++) {
            carry = carry + num1[i] + num2[i];
            sum.push_back(carry % 10);
            carry /= 10;
        }
        while(i < num1Size) {
            carry = carry + num1[i];
            sum.push_back(carry % 10);
            carry /= 10;
            i++;
        }
        while(carry) {
            sum.push_back(carry % 10);
            carry /= 10;
        }
    }
    else {
        for (i = 0; i < num1Size; i++) {
            carry = carry + num1[i] + num2[i];
            sum.push_back(carry % 10);
            carry /= 10;
        }
        while(i < num2Size) {
            carry = carry + num2[i];
            sum.push_back(carry % 10);
            carry /= 10;
            i++;
        }
        while(carry) {
            sum.push_back(carry % 10);
            carry /= 10;
        }
    }

    return sum;
}
void printNumber(const vector<int> &num) {
    for(auto i = num.rbegin(); i != num.rend(); i++) {
        std::cout << *i;
    }
    cout << endl;
}
void fib(vector<int> &num1, vector<int> &num2, vector<int> &num3) {
    num1 = num2;
    num2 = num3;
    num3 = strSum(num1, num2);
}
