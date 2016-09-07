#include <iostream>

bool isLeapYear(int n);

int main(int argc, const char *argv[])
{
    int day = 1; // MON = 1, TUE = 2, ... SAT = 6, SUN = 0
    int year = 1900;

    day = (day + 365) % 7;
    year++;

    std::cout << isLeapYear(1900) << " " << isLeapYear(1901) << std::endl;
    return 0;
}
bool isLeapYear(int n) {
    return year % 4 == 0 && year % 400 != 0;
}
