#include <iostream>

int main(int argc, const char *argv[])
{
    int productOfPrimes = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
    int n = productOfPrimes;

    while(n % 20 || n % 18 || n % 14)
        n += productOfPrimes;

    std::cout << n << std::endl;

    for (int i = 20; i > 0; i--) {
        std::cout << "i :"<<i<<", 나머지: " << n % i << std::endl;
    }

    return 0;
}
