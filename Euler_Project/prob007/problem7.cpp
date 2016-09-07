#include <iostream>
#include <cmath>

bool isPrime(int N) {
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

int main(int argc, const char *argv[])
{
    int k = 10001;
    int primeCount = 1; // for the only even prime.
    int prime = 0;
    
    for (int i = 3; primeCount < k; i += 2) {
        if(isPrime(i)) {
            prime = i;
            primeCount++;
        }
    }

    switch(k % 10) {
        case 1:
            std::cout << k <<"st ";
            break;
        case 2:
            std::cout << k <<"nd ";
            break;
        case 3:
            std::cout << k <<"rd ";
            break;
        default:
            std::cout << k <<"th ";
    }
    std::cout << "prime: "<< prime << std::endl;
    return 0;
}
