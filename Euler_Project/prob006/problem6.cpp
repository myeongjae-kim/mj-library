#include <iostream>

int main(int argc, const char *argv[])
{
    auto sumOfSquares = [](int n) -> int {
        return (n * (2*n + 1) * (n + 1)) / 6;
    };
    auto squareOfSum = [](int n) -> int {
        int sum = (n * (n + 1)) / 2;
        return sum * sum;
    };
    int n = 100;

    std::cout << "Sum square difference of" << n << ": ";
    std::cout << squareOfSum(n) - sumOfSquares(n) << std::endl;

    return 0;
}
