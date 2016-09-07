#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


int main(int argc, const char *argv[])
{
    int productOfPrimesBelow20 = 0;
    int count = 0, i = 0;
    auto isPrime = [](int N)->bool {
        int factor = 2;
        int maxFactor = sqrt(N);

        if(N % factor == 0)
            return false;

        factor = 3;
        while(factor <= maxFactor)
        {
            if(N % factor == 0)
                return false;
            factor += 2;
        }

        return true;
    };
    vector<int> v;
    int n = 2;

    while(n <= 20)
    {
        if(isPrime(n))
            v.push_back(n++);
    }


    while(n % 20 || n % 18 || n % 16 || n % 14)
    {
        n += productOfPrimesBelow20;
        count++;
    }

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
