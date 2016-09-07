#include <iostream>

bool isPythagoreanTriplet(int a, int b, int c) {
    return a * a + b * b == c * c;
}

int main(int argc, const char *argv[])
{
    int count = 0;
    int a = 332;
    int b = 0, c = 0;
    bool answerFound = false;

    while(a > 0)
    {
        b = a + 1;
        c = 1000 - (a + b);
        do {
            if(isPythagoreanTriplet(a, b, c)) {
                answerFound = true;
                break;
            }
            b++;
            c--;
            count++;
        }while(b < c);

        if(answerFound)
            break;
        else
            a--;
    }

    if(answerFound)
        printf("a = %d, b = %d, c = %d\nabc = %d\n", a, b, c, a * b * c);
    else
        printf("Answer not found.\n");

    std::cout << std::endl << "Calculation count: " << count << std::endl;

    return 0;
}
