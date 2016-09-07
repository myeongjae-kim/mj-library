#include <iostream>
#include <unordered_map>
#include <chrono>
using namespace std;

int getCollatzChainNumber(long n);

int main(int argc, const char *argv[])
{
    int answer = 0;
    int maxCollatzNumber = 0;

    auto startTime = std::chrono::system_clock::now();

    for (int i = 1; i < 5000000; i += 2) {
        int collatzNumber = getCollatzChainNumber(i);

        if(maxCollatzNumber < collatzNumber)
        {
            maxCollatzNumber = collatzNumber;
            answer = i;
        }
    }

    auto endTime = std::chrono::system_clock::now();

    std::cout << std::chrono::duration<double, milli>(endTime - startTime).count() / 1000.0 << std::endl;

    std::cout << "answer:" << answer << std::endl;
    
    return 0;
}

int getCollatzChainNumber(long n)
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
