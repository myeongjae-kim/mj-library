#include <iostream>
#include <unordered_map>
using namespace std;

int lettersNumber(unordered_map<int, int> &map, int n);
int getLettersOneDigitNumber(unordered_map<int, int> &map, int n);
int getLettersTwoDigitNumber(unordered_map<int, int> &map, int n);
int getLettersThreeDigitNumber(unordered_map<int, int> &map, int n);

int main(int argc, const char *argv[])
{
    unordered_map<int, int> map;
    string buff;
    
    map[0] = 0;
    buff = "one"; map[1] = buff.size();
    buff = "two"; map[2] = buff.size();
    buff = "three"; map[3] = buff.size();
    buff = "four"; map[4] = buff.size();
    buff = "five"; map[5] = buff.size();
    buff = "six"; map[6] = buff.size();
    buff = "seven"; map[7] = buff.size();
    buff = "eight"; map[8] = buff.size();
    buff = "nine"; map[9] = buff.size();
    buff = "ten"; map[10] = buff.size();
    buff = "eleven"; map[11] = buff.size();
    buff = "twelve"; map[12] = buff.size();
    buff = "thirteen"; map[13] = buff.size();
    buff = "fourteen"; map[14] = buff.size();
    buff = "fifteen"; map[15] = buff.size();
    buff = "sixteen"; map[16] = buff.size();
    buff = "seventeen"; map[17] = buff.size();
    buff = "eighteen"; map[18] = buff.size();
    buff = "nineteen"; map[19] = buff.size();
    buff = "twenty"; map[20] = buff.size();
    buff = "thirty"; map[30] = buff.size();
    buff = "forty"; map[40] = buff.size();
    buff = "fifty"; map[50] = buff.size();
    buff = "sixty"; map[60] = buff.size();
    buff = "seventy"; map[70] = buff.size();
    buff = "eighty"; map[80] = buff.size();
    buff = "ninety"; map[90] = buff.size();
    buff = "hundred"; map[100] = buff.size();
    buff = "thousand"; map[1000] = buff.size();
    
    int answer = 0;
    for (int i = 1; i <= 1000; i++) {
        answer += lettersNumber(map, i);
        cout << "i :" << i << ", lettersNumber: " << lettersNumber(map, i)<< endl;
    }
    
    cout << answer << endl;
    
    return 0;
}
int lettersNumber(unordered_map<int, int> &map, int n)
{
    if( n == 1000)
        return map[1] + map[n];
    
    if(100 <= n && n < 1000) {
        return getLettersThreeDigitNumber(map, n);
    }
    
    if(10 <= n && n < 100) {
        return getLettersTwoDigitNumber(map, n);
    }
    
    if(n < 10) {
        return getLettersOneDigitNumber(map, n);
    }
    
    
    return 0;
}
int getLettersThreeDigitNumber(unordered_map<int, int> &map, int n){
    int hunds = n / 100;
    int twodigit = n % 100;
    
    if(twodigit == 0)
        return map[hunds] + map[100];
    else
        return map[hunds] + map[100] + 3 + getLettersTwoDigitNumber(map, twodigit); // 3 is "and"
    
}
int getLettersTwoDigitNumber(unordered_map<int, int> &map, int n){
    if(n < 20)
        return map[n];
    
    int tens = n / 10;
    int ones = n % 10;
    
    return map[tens * 10] + getLettersOneDigitNumber(map, ones);
}
int getLettersOneDigitNumber(unordered_map<int, int> &map, int n){
    return map[n];
}
