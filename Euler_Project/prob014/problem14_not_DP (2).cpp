#include <iostream>
#include <unordered_map>
using namespace std;

int getCollatzChainNumber(const int n);

int main(int argc, const char *argv[])
{
    int answer = 0;
    int maxCollatzNumber = 0;

    for (int i = 1; i < 1000000; i += 2) {
        int collatzNumber = getCollatzChainNumber(i);

        if(maxCollatzNumber < collatzNumber)
        {
            maxCollatzNumber = collatzNumber;
            answer = i;
        }
    std::cout << i << std::endl;
    }

    std::cout << "answer:" << answer << std::endl;
    
    return 0;
}

int getCollatzChainNumber(int n)
{
    int count = 1;

    while(n != 1) {
        if(n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        count++;
    }

    return count;
}
