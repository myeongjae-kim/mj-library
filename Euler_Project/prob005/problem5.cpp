#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(int argc, const char *argv[])
{
    int productOfPrimesBelow20 = 0;
    int n = 0;
    int count = 0, i = 0;
    auto isPrime = [](int N)->bool {
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
    };
    vector<int> v;

    for (int ibuff = 2; ibuff <= 20; ibuff++) {
        if(isPrime(ibuff))
            v.push_back(ibuff);
    }

    productOfPrimesBelow20 = 1;
    for (auto j : v) {
        productOfPrimesBelow20 *= j;
    }

    do {
        n += productOfPrimesBelow20;
        count++;
    } while(n % 20 || n % 18 || n % 16 || n % 14);

    std::cout <<"Answer: "<< n << std::endl;
    std::cout <<"while loop count: " << count << std::endl << std::endl;

    std::cout << "Correctness: ";
    for (i = 20; i > 0; i--) {
        if(n % i != 0)
        {
            std::cout << "It is not correct.\n" << std::endl;
            break;
        }
    }
    if(i == 0)
    {
        std::cout << "OK!\n" << std::endl;
    }

    return 0;
}
