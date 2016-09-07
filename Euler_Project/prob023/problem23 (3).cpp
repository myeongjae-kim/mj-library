#include <iostream>
#include <cmath>
#include <vector>
#include <set>

#define MAX 28124

using namespace std;

bool isPrime(int N);

int sumOfDivisors(const int N);
set<int> primes;

bool isAbundant(const int N);

int main(int argc, const char *argv[])
{
    primes.insert(2);
    primes.insert(3);

    vector<int> abundantNumbers;

    for (int i = 1; i < MAX; i++) {
        if(isAbundant(i)) {
            abundantNumbers.push_back(i);
        }
    }

    set<int> sumsOfTwoAbundantNumbers;

    for(auto i = abundantNumbers.begin(); i != abundantNumbers.end() && *i <= MAX/2; i++) {
        cout << *i << endl;
        for(auto j = abundantNumbers.begin(); j != abundantNumbers.end(); j++) {
            int sum = *i + *j;
            if(sum < MAX)
                sumsOfTwoAbundantNumbers.insert(sum);
            else
                break;
            sum = 0;
        }
    }

    int answer = 0;
    for (int i = 1; i < MAX; i++) {
        if( *(sumsOfTwoAbundantNumbers.find(i)) == false) {
            answer += i;
        }
    }

    cout << endl;
    std::cout << "Answer: "<< answer << std::endl;
    
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

int sumOfDivisors(const int N) {
    if(N == 0) return 0;
    
    int lastPrime = 0;
    vector<int> exponents;
    vector<int> thisPrime;
    int tempN = N;
    
    int exp = 0;
    
    for (auto p: primes) {
        exp = 0;
        while(tempN % p == 0)
        {
            exp++;
            tempN /= p;
        }
        lastPrime = p;
        if(exp != 0) {
            exponents.push_back(exp);
            thisPrime.push_back(p);
        }
        if(p > tempN && lastPrime >= 3) break; // lastPrime should same or bigger than 3 because of next procedure.
    }
    
    if(tempN >= lastPrime) {
        for (int i = lastPrime + 2; i <= tempN; i += 2) {
            exp = 0;
            if(isPrime(i))
            {
                primes.insert(i);
                while(tempN % i == 0)
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
    
    // 소인수를 곱해가면서 약수를 찾는다.
    // 1에 첫번째 소인수를 곱해서 약수를 구한다.
    // 첫번쨰 소인수가 2고 차수가 3이라면
    // 1 * 2, 1 * 2 * 2, 1 * 2 * 2 * 2 를 divisors 벡터에 추가한다.
    // 방금 찾아놓은 약수들에 다음 소인수를 같은 방식으로 곱하고
    // divisors 벡터에 추가한다.
    // 이렇게 하면 자기 자신을 포함한 모든 약수를 구할 수 있다.
    
    for (int j = 0; j < thisPrime.size(); j++) {        // for all the primeFactor
        int divisorsSize = divisors.size();             // 지금까지 찾아진 약수까지만 소인수를 또 곱한다.
        for(auto i = 0; i != divisorsSize; i++) {
            int temp = divisors[i];
            for (int k = 0; k < exponents[j]; k++) {    // 약수에 소인수를 곱해서 벡터에 추가한다. 차수만큼 반복.
                temp *= thisPrime[j];
                divisors.push_back(temp);
            }
        }
    }
    
    int answer = 0;
    for (auto div: divisors) {
        answer += div;
    }
    
    return answer - N; // answer에는 자기 자신까지 포함되어 있음. 문제에서는 자기 자신은 제외한다.
}

bool isAbundant(const int N) {
    if(N < sumOfDivisors(N))
        return true;
    else
        return false;
}
