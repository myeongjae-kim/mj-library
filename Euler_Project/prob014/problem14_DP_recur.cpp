#include <iostream>
#include <unordered_map>
#include <chrono>

using namespace std;

int getCollatzChainNumber(unordered_map<long, int> &map, const long n);

int main(int argc, const char *argv[])
{
    long answer = 0;
    int maxCollatzNumber = 0;
    unordered_map<long, int> collatzChainMap;
    
    auto startTime = std::chrono::system_clock::now();
    
    for (long i = 1; i < 5000000; i += 2) {
        int collatzNumber = getCollatzChainNumber(collatzChainMap, i);
        
        if(maxCollatzNumber < collatzNumber)
        {
            maxCollatzNumber = collatzNumber;
            answer = i;
        }
    }
    
    auto endTime = std::chrono::system_clock::now();
    std::cout << std::chrono::duration<double, milli>(endTime - startTime).count() / 1000.0 << std::endl;
    
    std::cout << answer << std::endl;
    
    return 0;
}

int getCollatzChainNumber(unordered_map<long, int> &map, const long n)
{
    int collatzNumber = 0;
    long iBuff = n;
    
    if(n == 1)
        return map[n] = 1;
    
    if((collatzNumber = map[iBuff]) != 0)
        return collatzNumber;
    
    if(iBuff % 2 == 0)
        return map[iBuff] = getCollatzChainNumber(map, iBuff / 2) + 1;
    else
        return map[iBuff] = getCollatzChainNumber(map, 3 * iBuff + 1) + 1;
    
}
