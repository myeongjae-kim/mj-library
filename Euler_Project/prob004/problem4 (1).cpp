//
//  main.cpp
//  C++ Learning
//
//  Created by Do you remember me... on 8/23/16.
//  Copyright © 2016 KimMyeong-jae. All rights reserved.
//

#include <iostream>
#include <cstring>

#define STRSIZE 7

bool isPalindrome(int n);

int main(int argc, const char *argv[])
{
    int i = 999, j = 999;
    bool decrementChanger = false;
    char result[STRSIZE] = {0};
    
    while(i >= 100 & j >= 100)
    {
        if(isPalindrome(i * j))
        {
            std::cout << "The largest palindrome made from the product of two 3-digit numbers: "<< product << std::endl;
            return 0;
        }
        
        decrementChanger = !decrementChanger;
        if(decrementChanger == true)
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    return 0;
}

bool isPalindrome(int n)
{
    int begin = 0;
    int end = STRSIZE - 1;
    char result[STRSIZE] = {0};

    snprintf(result,STRSIZE, "%6d", n);

    while( begin < end)
    {
        if(result[begin] == result[end])
        {
            begin++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
