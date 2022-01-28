#pragma once
#include "BaseScene.h"

class Begining : public BaseScene
{
    public:
    Begining()
    {
        
    }
    std::string ManageInput()  override
    {   
        std::cout << "Press enter when ready...\n";
        std::cin.ignore();    
        return nextScenes[2];
    };

    void Render()  override
    {       
        Intro();
        std::cout << "Long texts would be interupted with (...) this means you have to press ENTER in order to proceed";
        std::cin.ignore();
        std::cout << "\nAnyways let us begin, shall we? (...)\n";
        std::cin.ignore();      
    };  
    
    void Intro() override
    {
        print_signs('-');
        std::cout << "This is the intro to the game \n";
    }

    std::string Present() override
    {
       

        return "Entering: " + name + "...\n";
    }
 

    ~Begining();
private:
bool flag = true;
    std::string name = "The streets";
    std::string nextScenes[3] = {"Error", "Exit", "JunkYard"};
};



