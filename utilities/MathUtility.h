#pragma once
#include <iostream>
#include <stdio.h>
int InputNumber();

class MathUt
{
    public:
    int InputNumber() 
    {
    std::string str;
    std::cin >> str;
    for (long unsigned int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == false)
            return -1; 
    return stoi(str);
    }
};