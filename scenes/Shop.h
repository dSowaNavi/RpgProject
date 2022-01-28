#pragma once
#include <cstdlib>
#include <ctime>
#include "BaseScene.h"
#include "../entities/Player.h"

class Shop : public BaseScene
{
    public:
    Shop(Player* mc)
    {        
        player = mc;
    }
    std::string ManageInput()  override
    {   
        bool done = false;
        std::string input;        
          
         while(!done)
        {
            input = "";
            std::cout<<"";
            std::cin >> input;   
            if(input == "1" || input == "buy" )
            {                
                BuyMenu();
                Render();
            }
            else if(input == "2" || input == "rumours" )
            {
                
                Quote();
                Render();
            }
            else if(input == "3" || input == "leave" )
            {
                std::cout << "you continued on your journey\n";                
                
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
    };

    void Render()  override
    {        
    if(flag)
        Intro();
    std::cout<< "What can I do for ya?: \n";      
    std::cout<< "1)buy\n";
    std::cout<< "2)rumours\n";
    std::cout<< "3)leave\n";
    };  
    
    std::string Present() override
    {
        return "Entering: " + name + "...\n";
    }

    void Intro() override
    {
    print_signs('#');
    std::cout << "\nWelcome to me shop lad.\n";
    print_signs('#');
    std::cout<<"\n";
    flag = false;
    }


    void Quote() 
    {
        srand(time(0));
        int index = 0+(rand()%5);
        std::cout<< "\"" <<quotes[index] << "\"(...)\n";
        std::cin.ignore();
    }

    void BuyMenu()
    {
        
        print_signs('=');
        std::cout<< "\ncheck out these beauties: \n";
        std::cout<< "    buff for " << costs[0] << "!\n";
        std::cout<< "    healing for " << costs[1] << "!\n";
        std::cout<< "Anything of interest?\n";
        int playerGold= player->ReturnStats('G');
        ShopSnipet(playerGold);        

        std::string input;
        bool done = false;
        while(!done)
        {
           //CHECK PLAYER GOLD
            input = "";
            ShopSnipet(playerGold);
            std::cin >> input;   

            if(input == "1" || input == "buff" )
            {                
                if(playerGold < costs[0])
                {
                    std::cout<<"Not enough Gold.\n";
                }
                else
                {
                    std::cout<<"Sold!.\n";
                    player->ManageBackpack("PotionOfStrength", 1);
                }
            }
            else if(input == "2" || input == "healing" )
            {                
                if(playerGold < costs[1])
                {
                    std::cout<<"Not enough Gold.\n";
                }
                else
                {
                    std::cout<<"Sold!.\n";
                    player->ManageBackpack("PotionOfHealing", 1);
                }
            }
            else if(input == "3" || input == "leave" )
            {
             done = true;
            }            
            else
            {
                std::cout << "invalid input.";                
            }
        }   
    }

    void ShopSnipet(int playerGold)
    {         
        print_signs('#');
        std::cout<< "Player gold: " << playerGold << "\n";
        std::cout<< "1) Buy buffs?\n";
        std::cout<< "2) Buy healing?\n";
        std::cout<< "3) leave?\n";        
        std::cout<< "\n";
    }
    ~Shop();
private:
    bool flag = true;
    int costs[2] = {10,3};
    std::string name = "Shady Shop";
    std::string nextScenes[3] = {"Error", "Exit", "JunkYard"};
    std::string quotes[5] = {
        "Have you heard of the high Elves? Goodbye.", 
        "I don't like to think about zombies. Missing arms, legs, heads. They smell awful, and they're hard to kill.",
        "The Gray Fox sounds like a dangerous thief.",
        "Shh Hear that?... Eh must have been the wind.",
        "I ran across a ghost once. Seemed to suck the energy right out of me."
        };
    Player* player;
};



