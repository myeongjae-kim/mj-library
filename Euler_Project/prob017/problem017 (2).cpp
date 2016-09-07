#include <iostream>
#include <unordered_map>
using namespace std;

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
    buff = "tweleve"; map[12] = buff.size();
    buff = "thirteen"; map[13] = buff.size();
    buff = "fourteen"; map[14] = buff.size();
    buff = "fifteen"; map[15] = buff.size();
    buff = "sixteen"; map[16] = buff.size();
    buff = "seventeen"; map[17] = buff.size();
    buff = "eighteen"; map[18] = buff.size();
    buff = "nineteen"; map[19] = buff.size();
    buff = "twenty"; map[20] = buff.size();
    buff = "thirty"; map[30] = buff.size();
    buff = "fourty"; map[40] = buff.size();
    buff = "fifty"; map[50] = buff.size();
    buff = "sixty"; map[60] = buff.size();
    buff = "seventy"; map[70] = buff.size();
    buff = "eighty"; map[80] = buff.size();
    buff = "ninety"; map[90] = buff.size();
    buff = "hundred"; map[100] = buff.size();
    buff = "thousand"; map[1000] = buff.size();

    int answer = 0;
    int i = 1;

    // 1-digit number;

    while( i < 10) {
        ansewr += map[i];
        i++;
    }

    // 2-digit number;
    // below 20

    while( i < 20 ) {
        answer += map[i];
        i++;
    }

    // above 20
    while( i < 100) {
        int tens = i / 10;
        int ones = i % 10;
        answer += map[tens * 10] + map[ones];
        i++;
    }

    // 3-digit number;
    while( i < 999) {
        int hunds = i / 100;
        int mods = i % 100;
        if( mods < 20 ) {
            answer += map[hunds] + map[100] + map[mods];
        }
        else {
            int tens = i / 10;
            int ones = i % 10;
            answer += map[hunds] + map[100] + map[tens * 10] + map[ones];
        }

        i++;
    }



/*     // 1-digit, 2-digit number
 *     for (int i = 1; i <= 19; i++) {
 *         answer += map[i];
 *     }
 *     for (int i = 20; i <= 90; i += 10) {
 *         for (int j = 0; j <= 9; j++) {
 *             answer += map[i] + map[j];
 *         }
 *     }
 * 
 *     // 3-digit number
 *     for (int i = 100; i <= 900; i+= 100) {
 *         for (int j = 0; j <= 19; j++) {
 *             answer += map[i / 100] + map[i] + map[j];
 *         }
 * 
 *         for (int j = 20; j <= 90; j += 10) {
 *             for (int k = 0; k <= 9; k++) {
 *                 answer += map[i / 100] + map[i] + map[j] + map[k];
 *             }
 *         }
 *     }
 *      
 *     // 4-digit number
 *     answer += map[1] + map[1000];
 *  */
    cout<< answer << endl;

    return 0;
}
