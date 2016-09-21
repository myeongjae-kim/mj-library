#include <iostream>
#include "mjUtil.h"
 
int sumOfMultiple(int);
int MAX = 0;
 
int main(int argc, char const *argv[])
{
    int sum = 0;
    char flag = 0;

    do {
        std::cout << "Find the sum of all the multiples of 3 or 5 below a number you input: ";
        std::cin >> MAX;
        FLUSH();

        MAX--; // because of the 'below' of the problem.

        sum = sumOfMultiple(3) + sumOfMultiple(5) - sumOfMultiple(15);
        std::cout << "Answer: "<< sum << std::endl;

        std::cout << "Do it again? (y/n): ";
        flag = getchar();
        FLUSH();

    }while(flag == 'y' || flag == 'Y');

    return 0;
}
 
int sumOfMultiple(int param)
{
    int n = MAX / param;
    return param * (n * (n + 1) / 2);
}
