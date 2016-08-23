#include <iostream>

int main(int argc, const char *argv[])
{
    int productOfPrimesBelow20 = 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19;
    int n = productOfPrimesBelow20;
    int count = 0;

    while(n % 20 || n % 18 || n % 16 || n % 14)
    {
        n += productOfPrimesBelow20;
        count++;
    }

    std::cout <<"answer: "<< n << std::endl;
    std::cout <<"while loop count: " << count << std::endl << std::endl;

    for (int i = 20; i > 0; i--) {
        printf("%d %% %2d = %d\n", n, i, n % i );
    }

    return 0;
}
