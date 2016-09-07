#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

bool isPrime(int N);
bool isAmicable(int N);

int sumOfDivisors(const int N);
set<int> primes;

int main(int argc, const char *argv[])
{
    primes.insert(2);
    primes.insert(3);

    cout << sumOfDivisors(220) - 220<< endl;
    
    return 0;
}


bool isPrime(int N) {
    for (auto i : primes) {
        if( i == N ) return true;
    }
    
    if(N == 1) return false;    // 1은 소수가 아니다.
    if(N < 4) return true;      // 2 and 3 are prime.

    int factor = 2;
    if(N % factor == 0) return false;   // 2를 제외한 모든 소수는 홀수다
    
    if(N < 9) return true;  //we have already excluded 4,6 and 8.

    factor = 3;
    if(N % factor == 0) return false;

    int maxFactor = sqrt(N);
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

bool isAmicable(int N) {
    int lastPrime = 0;
    vector<int> exponents;
    
    int exp = 0;
    
    for (auto p: primes) {
        exp = 0;
        while(N % p == 0)
        {
            exp++;
            N /= p ;
        }
        lastPrime = p;
        if(exp != 0)
            exponents.push_back(exp);
        if(p > N) break;
    }
    
    if(N >= lastPrime) {
        for (int i = lastPrime + 2; i <= N; i += 2) {
            exp = 0;
            if(isPrime(i))
            {
                primes.insert(i);
                while(N % i == 0)
                {
                    exp++;
                    N /= i;
                }
                if(exp != 0)
                    exponents.push_back(exp);
            }
        }
    }
    
    int divisors = 1;
    for (auto e : exponents) {
        divisors *= (e + 1);
    }
    
    return divisors;
}
int sumOfDivisors(const int N) {
    int lastPrime = 0;
    vector<int> exponents;
    vector<int> thisPrime;
    int tempN= N;
    
    int exp = 0;
    
    for (auto p: primes) {
        exp = 0;
        while(N % p == 0)
        {
            exp++;
            tempN/= p;
        }
        lastPrime = p;
        if(exp != 0) {
            exponents.push_back(exp);
            thisPrime.push_back(p);
        }
        if(p > N) break;
    }
    
    if(N >= lastPrime) {
        for (int i = lastPrime + 2; i <= N; i += 2) {
            exp = 0;
            if(isPrime(i))
            {
                primes.insert(i);
                while(N % i == 0)
                {
                    exp++;
                    tempN /= i;
                }
                if(exp != 0)
                {
                    exponents.push_back(exp);
                    thisPrime.push_back(i);
                }
            }
        }
    }

    // make a table and calculate divisors.
    vector<int> divisors;
    divisors.push_back(1);

    for (int j = 0; j < thisPrime.size(); j++) {        // for all the primeFactor
        for (auto divisor : divisors) {
            int temp = divisor;
            for (int k = 0; k < exponents[j]; k++) {
                temp *= thisPrime[j];
                divisors.push_back(temp);
            }
        }
    }


    int answer = 0;
    for (auto div: divisors) {
        answer += div;
    }
    
    return answer - N;
}
