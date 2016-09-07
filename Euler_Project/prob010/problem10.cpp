#include <iostream>
#include <cmath>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

class IsPrime
{
public:
    bool operator()(int N) {
        if(N == 1) return false;    // 1은 소수가 아니다.
        if(N < 4) {
            return true;      // 2 and 3 are prime.
        }
        
        int factor = 2;
        if(N % factor == 0) return false;   // 2를 제외한 모든 소수는 홀수다
        
        if(N < 9) {
            return true;  //we have already excluded 4,6 and 8.
        }
        
        factor = 3;
        if(N % factor == 0) return false;
        
        int maxFactor = sqrt(N);
        
        count++;
        
        factor = 5;     // 3보다 큰 소수는 (6k ± 1) 형태로 나타낼 수 있다. 최소는 5.
        while(factor <= maxFactor) {
            if(N % factor == 0)         // (6k - 1) 체크.
                return false;
            if(N % (factor + 2) == 0)   // (6k + 1) 체크.
                return false;
            factor += 6;    // 소수는 (6k ± 1) 형태이므로 factor는 6씩 증가한다.
        }
        return true;
    }
    
    static int count;
};

int IsPrime::count = 0;


int main(int argc, const char *argv[])
{
    int primeCount = 1, i = 0;
    long sumOfPrimes = 2;
    IsPrime isPrime;
    auto startTime = system_clock::now();
    
    for (i = 3; i <= 2000000 ; i += 2) {
        if(isPrime(i)) {
            primeCount++;
            sumOfPrimes += i;
            // printf("%d\n", i);
        }
    }
    auto endTime = system_clock::now();
    
    printf("%ld\n", sumOfPrimes);
    std::cout << "Calculating Time: " << duration<double, std::milli>(endTime - startTime).count() / 1000.0 << std::endl;
    std::cout << IsPrime::count << std::endl;
    
    return 0;
}
