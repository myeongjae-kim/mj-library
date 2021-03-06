#include <iostream>
#include <vector>
using namespace std;

void strMultiple(vector<int> &num, int n);
vector<int> strSum(vector<int> &num1, vector<int> &num2);
vector<int> strReturnProduct(const vector<int> &num, const int n); // n should b 1-digit integer.
void printNumber(const vector<int> &num);

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(1);

    for (int i = 1; i <= 100; i++) {
        strMultiple(num, i);
    }

    printNumber(num);

    int answer = 0;
    for (auto i : num) {
        answer += i;
    }
    std::cout << "Answer: " << answer<< std::endl;
    return 0;
}

void strMultiple(vector<int> &num, int n) {
    if(0 <= n && n < 10) {
        num = strReturnProduct(num, n);
    }
    else if ( 10 <= n && n  < 100) {
        int tens = n / 10;
        int ones = n % 10;

        vector<int>&& onesProduct = strReturnProduct(num, ones);

        num.insert(num.begin(), 0);
        vector<int>&& tensProduct = strReturnProduct(num, tens);

        num = strSum(tensProduct, onesProduct);
    }
    else { // this case is 100 only.
        num.insert(num.begin(), 0);
        num.insert(num.begin(), 0);
    }
}

vector<int> strReturnProduct(const vector<int> &num, const int n) {
    vector<int> product;
    int carry = 0;

    for (auto c : num) {
        carry = carry + c * n;
        product.push_back(carry % 10);
        carry /= 10;
    }
    if(carry)
        product.push_back(carry);

    return product;
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
