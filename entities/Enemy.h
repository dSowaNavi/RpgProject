#pragma once
#include "BaseEntity.h"

class Enemy: public BaseEntity
{
public:
    Enemy(std::string name, int chalangeRating, int hp, int dmg)
    {
        Name = name;
        CR = chalangeRating;
        HealthPoints = hp;
        Dice = dmg;
        MaxHealthPoints = hp;
    };
    void Update() override
    {
        if(HealthPoints <= 0)
        {
           std::cout<< Name <<" perished!\n";
           shouldPop = true;
        }
        
    };

    void AffectHealth(int damage) override
    {
        if(damage < 0)
        std::cout<< Name << " takes: " << -damage <<" damage!\n";
        else if(damage < 0)
        std::cout<< Name << " heals for: " << -damage <<" HP!\n";
        else
        std::cout<< "Rolled 0 for: "<< Name << "!\n";
        HealthPoints = HealthPoints + damage;
        Update();
        
    };

    void Present() override
    {        
        std::cout << Name << " Hp:" << HealthPoints << "/" << MaxHealthPoints << "\n";
    }

    int RollDamage() override
    {
		srand(time(0));
		int damage = 1+(rand()%Dice);
        return damage;
    }
    
    bool shouldPop = true;
    int HealthPoints;
private:
	int MaxHealthPoints;
    int CR;
    int Dice;
	std::string Name;	
};