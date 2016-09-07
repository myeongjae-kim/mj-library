#include <iostream>
#include <unordered_map>

int getCollatzChainNumber(unordered_map<int, int> &map, const int n);

int main(int argc, const char *argv[])
{
    int answer = 0;
    int maxCollatzNumber = 0;
    unordered_map<int, int> collatzChainMap;

    for (int i = 1; i < 1000000; i += 2) {
        int collatzNumber = getCollatzChainNumber(collatzChainMap, i);
        if(maxCollatzNumber < collatzNumber)
        {
            maxCollatzNumber = collatzNumber;
            answer = i;
        }
        std::cout << "i: " << i << " maxCollatzNumber: "<< maxCollatzNumber << " answer: "<< answer << std::endl;
    }
    
    return 0;
}

int getCollatzChainNumber(unordered_map<int, int> &map, const int n)
{
    int count = 1;
    long iBuff = n;

    while(iBuff != 1) {
        if(map[iBuff] != 0) {
            count += map[iBuff];
            break;
        }

        if(iBuff % 2 == 0)
            iBuff /= 2;
        else
            iBuff = 3 * n + 1;
        count++;
    }

    return map[n] = count;
}
