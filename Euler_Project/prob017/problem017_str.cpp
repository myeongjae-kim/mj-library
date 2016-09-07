#include <iostream>
#include <unordered_map>
using namespace std;

int main(int argc, const char *argv[])
{
    unordered_map<int, string> map;
    string buff;
    
    map[0] = buff;
    buff = "one"; map[1] = buff;
    buff = "two"; map[2] = buff;
    buff = "three"; map[3] = buff;
    buff = "four"; map[4] = buff;
    buff = "five"; map[5] = buff;
    buff = "six"; map[6] = buff;
    buff = "seven"; map[7] = buff;
    buff = "eight"; map[8] = buff;
    buff = "nine"; map[9] = buff;
    buff = "ten"; map[10] = buff;
    buff = "eleven"; map[11] = buff;
    buff = "twelve"; map[12] = buff;
    buff = "thirteen"; map[13] = buff;
    buff = "fourteen"; map[14] = buff;
    buff = "fifteen"; map[15] = buff;
    buff = "sixteen"; map[16] = buff;
    buff = "seventeen"; map[17] = buff;
    buff = "eighteen"; map[18] = buff;
    buff = "nineteen"; map[19] = buff;
    buff = "twenty"; map[20] = buff;
    buff = "thirty"; map[30] = buff;
    buff = "forty"; map[40] = buff;
    buff = "fifty"; map[50] = buff;
    buff = "sixty"; map[60] = buff;
    buff = "seventy"; map[70] = buff;
    buff = "eighty"; map[80] = buff;
    buff = "ninety"; map[90] = buff;
    buff = "hundred"; map[100] = buff;
    buff = "thousand"; map[1000] = buff;
    
    int answer = 0;
    for (int i = 1; i <= 1000; i++) {
        int oldAnswer = answer;

        int ibuff = i;
        int thousands = ibuff / 1000;
        ibuff %= 1000;

        int hunds = ibuff / 100;
        ibuff %= 100;

        int tens = ibuff / 10;
        ibuff %= 10;

        int ones = ibuff;

        if(thousands) {
            cout << map[thousands] << " " << map[1000];

            answer += map[thousands].size() + map[1000].size();

        }
        else if(hunds) {
            cout << map[hunds] << " " << map[100];

            answer += map[hunds].size() + map[100].size();

            if(tens == 1) {
               cout << " and " << map[tens * 10 + ones];

                answer += 3 + map[tens * 10 + ones].size();

            }
            else if (tens) {
                cout << " and " << map[tens * 10];

                answer += 3 + map[tens * 10].size();

                if(ones) {
                    cout << "-" << map[ones];

                    answer += map[ones].size();
                }
            }
            else if (ones) {
                cout << " and " << map[ones];

                answer += 3 + map[ones].size();
            }
        }
        else if(tens) {
            if(tens == 1) {
               cout << map[tens * 10 + ones];

               answer += map[tens * 10 + ones].size();
            }
            else if (tens) {
                cout << map[tens * 10];

                answer += map[tens * 10].size();

                if(ones) {
                    cout << "-" << map[ones];

                    answer += map[ones].size();
                }
            }
        }
        else if(ones) {
            cout << map[ones];
            answer += map[ones].size();
        }
        std::cout << "\t\t\tletters: "<< answer - oldAnswer;
        std::cout << "\tanswer: "<< answer << std::endl;
    }

    cout << answer << endl;

    return 0;
}
