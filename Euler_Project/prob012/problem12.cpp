#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class IsPrime
{
public:
    bool operator()(int N);
};

class GetTheNumberOfDivisors
{
public:
    int operator()(int N);
    static vector<int> primes;
    
};

int main(int argc, const char *argv[])
{
    GetTheNumberOfDivisors::primes.push_back(2);
    GetTheNumberOfDivisors::primes.push_back(3);
    GetTheNumberOfDivisors getTheNumberOfDivisors;
    int i = 0;
    int triangleNumber = 0;
    int divisors = 0;
    
    while(divisors <= 500)
    {
        i++;
        triangleNumber += i;
        divisors = getTheNumberOfDivisors(triangleNumber);

        if(divisors >= 100)
        {
            if(divisors >= 300)
                printf("Triangle Number: %d, divisors: \x1b[33m%d\x1b[0m\n", triangleNumber, divisors);
            else
                printf("Triangle Number: %d, divisors: %d\n", triangleNumber, divisors);
        }
        
    }
    
    std::cout << triangleNumber<< std::endl;
    
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

vector<int> GetTheNumberOfDivisors::primes;
int GetTheNumberOfDivisors::operator()(int N) {
    int lastPrime = *(primes.end() - 1);
    vector<int> exponents;
    IsPrime isPrime;
    
    if(N/2 >= lastPrime) {
        for (int i = lastPrime + 2; i <= N/2; i += 2) {
            if(isPrime(i))
                primes.push_back(i);
        }
    }
    
    for (auto p : primes) {
        int exponent = 0;
        
        while(N % p == 0)
        {
            exponent++;
            N /= p;
        }
        exponents.push_back(exponent);
    }
    
    int divisors = 1;
    for (auto e : exponents) {
        divisors *= (e + 1);
    }
    
    return divisors;
}
