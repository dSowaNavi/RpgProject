#pragma once
#include <iostream>
#include <stdio.h>

class TextUt
{
    public:
    void print_signs(char sign, int amount)
    {
        int length;
        if (amount == 0)
        {length = 16;}
        else if (amount < 0) 
        {
            length = 16 + amount;
        }
        else
        {
            length = amount;
        }

        int i;             
        for(i = 0; i < length; i++)
            std::cout << sign;                    
    }
};