#include <iostream>
#include <cstdio>
#include <cmath>
#include "isPrime.h"
using namespace std;

bool isPrime(int N) {
    // for (auto i : primes) {
    //     if( i == N ) return true;
    // } // this is for Dynamic Programming
    
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

/* below is lambda function */
// int main(int argc, const char *argv[])
// {
//     auto isPrime = [](int N)->bool {
//         // for (auto i : primes) {
//         //     if( i == N ) return true;
//         // } // this is for Dynamic Programming
//         
//         if(N == 1) return false;    // 1은 소수가 아니다.
//         if(N < 4) return true;      // 2 and 3 are prime.
// 
//         int factor = 2;
//         if(N % factor == 0) return false;   // 2를 제외한 모든 소수는 홀수다
//         
//         if(N < 9) return true;  //we have already excluded 4,6 and 8.
// 
//         factor = 3;
//         if(N % factor == 0) return false;
// 
//         int maxFactor = sqrt(N);
//         factor = 5;     // 3보다 큰 소수는 (6k ± 1) 형태로 나타낼 수 있다. 최소는 5.
//         while(factor <= maxFactor) {
//             if(N % factor == 0)         // (6k - 1) 체크.
//                 return false;
//             if(N % (factor + 2) == 0)   // (6k + 1) 체크.
//                 return false;
//             factor += 6;    // 소수는 (6k ± 1) 형태이므로 factor는 6씩 증가한다.
//         }
//         return true;
//     };
// 
//     for (int i = 1; i <= 100; i++) {
//         if(isPrime(i))
//         {
//             printf("%d is prime.\n", i);
//         }
//     }
// 
//     return 0;
// }
