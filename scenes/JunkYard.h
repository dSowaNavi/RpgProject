#pragma once
#include <cstdlib>
#include <ctime>
#include "BaseScene.h"
#include "../entities/Player.h"

class JunkYard : public BaseScene
{
    public:
    JunkYard(Player* mc)
    {
     player = mc;   
    }
    std::string ManageInput()  override
    {   
        bool done = false;
        std::string input;        
          
         while(!done)
        {   
            Snippet();
            input = "";
            std::cout<<"";
            std::cin >> input;   
            if(input == "1" || input == "scavenge" )
            {                
                srand(time(0));
		        int find = 1+(rand()%10);
                std::cout << "Digging through the junk payed off!.\n";
                player->AddGold(find, 1);                       
            }
            else if(input == "2" || input == "shop" )
            {
                
                done = true;
                return nextScenes[3];
            }            
            else if(input == "3" || input == "move on" || input == "move" )
            {
                
                done = true;
                return nextScenes[2];
            }
            else
            {
                std::cout << "invalid input.";
                Render();
            }
        };
        return nextScenes[0];
    }

    void Render()  override
    {       
      if(flag)
        Intro();      
    };  
    
    void Intro() override
    {   
        print_signs('-');
        std::cout << "\nSoggy and Filty this place still might be of use to me.\n";
        std::cout << "Let's take a look around we might find something useful (...).\n";
        std::cin.ignore();
        std::cout<<"There's also a shop here (...)\n";
      flag = false;
    }

    void Snippet()
    {
        std::cout<<"So what should I do?\n";
      print_signs('=');
      std::cout<<"\n1) Scavenge for resources\n";
      std::cout<<"2) Check out the shop\n";      
      std::cout<<"3) Move on\n";
    }

    std::string Present() override
    {
        return "Entering: " + name + "...\n";
    }
    
    ~JunkYard();
private:
    bool flag = true;
    std::string name = "The Junkyard";
    std::string nextScenes[4] = {"Error", "Exit", "EndScene", "Shop"};
    Player* player;
};



