#include <iostream>
#include <cstring>

bool isPalindrome(int n);

int main(int argc, const char *argv[])
{
    int i = 0, j = 0;
    int x = 0, y = 0;
    int product = 0;
    int answer = 0;
    int calcNum = 0;
    int decrementNumber = 0;
    
    for (i = 999; i >= 100; i--) {
        if(i % 11 == 0)
        {
            /* if 'i' is a multiple of 11,
             * 'j' should be all three digit number. */

            j = 999;
            decrementNumber = 1;
        }
        else
        {
            /* if 'i' is not a multiple of 11,
             * 'j' should be multiples of 11 in three digit number. */

            j = 990; // 990 is the largest multiple of 11 in three digit number.
            decrementNumber = 11;
        }

        for (; j >= 100; j -= decrementNumber) {
            product = i * j;
            if(product <= answer)
                break; 

            calcNum++;
            if(isPalindrome(product))
            {
                answer = product;
                x = i;
                y = j;
            }
        }
    }
    
    printf("The largest palindrome made from the product of two 3-digit numbers: %d = %d * %d\n", answer, x, y);
    std::cout << calcNum << std::endl;
    return 0;
}

int reverseInt(int n)
{
    int reversed = 0;

    while(n > 0)
    {
        reversed = 10*reversed + n % 10;
        n /= 10;
    }
    return reversed;
}

bool isPalindrome(int n)
{
    return n == reverseInt(n);
}
