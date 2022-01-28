#pragma once
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../utilities/MathUtility.h"
#include "../utilities/TextUtility.h"

class CombatMngr
{
public:
    CombatMngr(Player* mc){
        player = mc;        
     };

void Run() 
{
    active = true;
    GenerateEncounter();
    while(active && player->ReturnStats('H') > 0)
    {        
        Render();
        ManageInput();
        AI();
    }
    if (!coward)
    {
    srand(time(0));
	int amount = 10+(rand()%20);    
    player ->AddGold(amount, 1);
    std::cout << "\n";
    }
}

void Render()  
{
    std::cout << "################\n";
    std::cout << "Prepare for combat!\n";
    RenderEnemies();        
}

void CombatSnipet()
{
    std::cout << "What will you do?\n";
    player->Present();    
    std::cout << "1) Attack\n";
    std::cout << "2) Item\n";
    std::cout << "3) Run\n";
}

void ManageInput()  
{   
    bool done = false;
    std::string input;
    
    int temp;    
    while(!done)
    {        
        CombatSnipet();
        input = "";
        std::cin >> input;
        if(input == "1" || input == "attack" )
        {   
            std::cout << "Which one? ";                                
            temp = MathUti.InputNumber();
            temp--;
            if(temp < 0 || temp > size)
                std::cout<<"invalid input\n";
            else
            {                
                enemies[temp]->AffectHealth(player->RollDamage());   
                CombatUpdate();  
                done = true;    
            }
        }
        else if(input == "2" || input == "item")
        {
            bool used = false;
            std::string answer;
            while(!used)
            { 
                TextUti.print_signs('-', 0);
                std::cout << "\n";
                player->PresentBackpack();
                std::cout << "Choose an item: \n";
                temp =MathUti.InputNumber();
                if (temp >= 0)
                {
                    std::cout << "use || exit : ";                
                    temp -= 1;
                    std::cin >> answer;
                }
                if(answer == "use" || answer == "1")
                {
                    bool check = player->usePotion(temp); 
                 
                    CombatUpdate();
                    used = true;
                    if(check)
                        done = true;
                
                }else if(answer == "exit" || answer == "3")
                {
                    used = true;
                    //do nothing
                }               
                else 
                    std::cout<<"invalid input";
            }
        }else if(input == "3" || input == "run") 
        {
            srand(time(0));
            int find = 1+(rand()%5);
            if(find == 1)
                std::cout << "Critical Failure, Escape failed!";
            else
            {
                done =true;
                coward = true;
                active = false;
                break;  
            }          
        }else
        {
            std::cout << "invalid input";
        }
        
    }
}    

void RenderEnemies()
{
    int i = 1;
    TextUti.print_signs('=', 0);
    std::cout << "\n";
    for(auto& elem : enemies)
    {
        std::cout << i << ") ";
        elem->Present();
        i++;
    }
    TextUti.print_signs('=', 0);
    std::cout << "\n";
}


void AI()
{    
    for(auto& elem : enemies)
    {
        player->AffectHealth(-elem->RollDamage());                      
    }   
    
}

void CombatUpdate()
{
    int index = 0;   
    
    for(auto& element : enemies)
    {         
        if(element->HealthPoints <= 0)
        {            
            
            popEntity(index);
            if(active == false)
            break;
            size--;
            index--;
        }
        index ++;
    }
}

void GenerateEncounter()
{
    srand(time(0));
    int rando = (rand()%3)  + 1;
    size = rando;
    int index;
    for(int i = 0 ; i < size ; i++)
    {
       index = (rand()%2); 
        pushEntity(index);
    }
}

void pushEntity(int index) 
{
    switch(index)
    {
        case 0:
            enemies.push_back(new Enemy("Goblin", 0, 5, 3));
        break;
        case 1:
            enemies.push_back(new Enemy("Bandit", 1, 10, 6));
        break;
    }
}

void popEntity(int where)
{    
    enemies.erase(enemies.begin() + where );    
    if(enemies.empty())
    {
        std::cout << "Victory!\n";
        active = false;
    }
};

~CombatMngr(){};
private:
int size;
bool active = true;
bool coward = false;
std::vector <Enemy*> enemies;
Player* player;
MathUt MathUti;
TextUt TextUti;
};