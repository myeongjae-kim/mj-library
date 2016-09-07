#include <iostream>

bool isLeapYear(int year);

int main(int argc, const char *argv[])
{
    int day = 1; // MON = 1, TUE = 2, ... SAT = 6, SUN = 0
    int year = 1900;
    int firstIsSunday = 0;

    year++;

    day += 365 - 31;
    while(year <= 2000) {
        // 1 JAN
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;

        // 1 FEB
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;

        // 1 MAR
        if(isLeapYear(year)) {
            if( (day = (day + 29) % 7) == 0) firstIsSunday++;
        }
        else {
            if( (day = (day + 28) % 7) == 0) firstIsSunday++;
        }
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;
        if( (day = (day + 30) % 7) == 0) firstIsSunday++;
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;
        if( (day = (day + 30) % 7) == 0) firstIsSunday++;
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;
        if( (day = (day + 30) % 7) == 0) firstIsSunday++;
        if( (day = (day + 31) % 7) == 0) firstIsSunday++;
        if( (day = (day + 30) % 7) == 0) firstIsSunday++;
        
        year++;
    }

    std::cout << firstIsSunday << std::endl;


    return 0;
}
bool isLeapYear(int year) {
    if(year % 100 == 0) {
        return year % 400 == 0;
    }
    else {
        return year % 4 == 0;
    }
}
