#pragma once
#include "BaseScene.h"

class EndScene : public BaseScene
{
    public:
    EndScene()
    {       
    }
    std::string ManageInput()  override
    {   
        std::cout << "Press enter to quit.\n";
        std::cin.ignore();
        return nextScenes[1];
    }

    void Render()  override
    {      
    if(flag)
        Intro();    
    };

    void Intro() override
    {   
        print_signs('#');
        std::cout<< "\nEnd card of the game\n";
      flag = false;
    }

    std::string Present() override
    {
        return "Entering: " + name + "...\n";
    }
    
    ~EndScene();
private:
    bool flag = true;
    std::string name = "??";
    std::string nextScenes[2] = {"Error", "Exit" };
};



