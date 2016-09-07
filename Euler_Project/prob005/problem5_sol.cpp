#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class IsPrime
{
public:
    bool operator()(int N);
};

int main(int argc, const char *argv[])
{
    int k = 20;
    vector<long> primes, exponents;
    IsPrime isPrime;

    for (int i = 2; i <= k; i++) {
        if(isPrime(i)) {
            primes.push_back(i);
        }
    }

    for (auto p : primes) {
        exponents.push_back(floor(log(k)/log(p)));
    }

    long answer = 1;
    std::cout << "Smallest Multiple of 1~"<<k<<": ";
    for (int i = 0; i < primes.size(); i++) {
        answer *= pow(primes[i],exponents[i]);
    }
    std::cout << answer << std::endl;

    return 0;
}

bool IsPrime::operator()(int N) {
    if(N == 2) return true;

    int factor = 2;
    if(N % factor == 0) return false;

    int maxFactor = sqrt(N);
    factor = 3;
    while(factor <= maxFactor) {
        if(N % factor == 0)
            return false;
        factor += 2;
    }

    return true;
}
