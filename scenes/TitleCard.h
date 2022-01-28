#pragma once
#include "BaseScene.h"

class TitleCard : public BaseScene
{
    public:
    TitleCard()
    {     
    }

    std::string ManageInput()  override
    {   
    std::string choice;
    bool done = false;
    while(!done)
    {
        std::cin>>choice;
        if(choice == "1" || choice == "start game" || choice == "start")
        {
            done = true;
            return nextScenes[2];
        }
        else if (choice == "2" ||  choice == "exit")
        {
            done = true;
            return nextScenes[1];
        }
        else 
        {
            std::cout << "invalid input";
        }        
    }
        return nextScenes[0];
    };
    void Render()  override
    {      
    if(flag)
        Intro();
    std::cout<< "Menu:\n";
    std::cout<< "1)Start game\n";
    std::cout<< "2)exit\n";    
    std::cout<< "What will you do?: ";
    };  

    void Intro() override
    {   
        print_signs('#');    
        std::cout << "\nThe Rpg Project.\n";
        print_signs('#');
        flag = false;
    }

    std::string Present() override{ return "";}

    ~TitleCard();
private:
    bool flag = true;
    std::string Name = "TitleCard";
    std::string nextScenes[3] = {"Error", "Exit", "Begining"};
};



