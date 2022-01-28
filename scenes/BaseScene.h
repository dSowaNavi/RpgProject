#pragma once
#include <iostream>
#include "../src/Game.h"

class BaseScene
{
public:    
    virtual std::string ManageInput() = 0;
    virtual void Render() = 0;     
    virtual std::string Present() = 0;    
    virtual void Intro() =0;
    void print_signs(char sign)
    {
        int i;             
        for(i = 0; i < 16; i++)
            std::cout << sign;       
              
    }
private:
std::string name;
};