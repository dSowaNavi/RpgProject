#pragma once
#include "BaseEntity.h"
#include <cstdlib>
#include <ctime>
#include <map>

class Player : public BaseEntity
{
public:
	Player()
	{
		
	};
	void AssignName()
	{
		std::cout <<"What name should our Hero have? ";
		std:: cin >> Name;
	}

	void AffectHealth(int damage) override
	{
		if (damage < 0)
		{
			std::cout<< Name << " takes: " << damage << "!\n";
		}
		else if (damage > 0)
		{
			std::cout<< Name << " Heals for: " << damage << "!\n";
		}
		else 
		{
			std::cout<< "its a fluke!\n";
		}
		HealthPoints = HealthPoints +  damage;		
		Update();
	};

	void Update() override
	{
		if(HealthPoints == 0)
		{
			std::cout<<"Player Death!\n";
			isDead = true;
		}
		else if(HealthPoints < 0)
		{
			std::cout<<"Player Overkill!!!" << HealthPoints << " in overkill\n";
			isDead = true;
		}		
		else if(HealthPoints > MaxHealthPoints)
			HealthPoints = MaxHealthPoints;
	};

	int RollDamage() override
    {
		if (buffed)
		{
			return -Dice;
			buffed = false;
		}
		else
		{
		srand(time(0));
		int damage = 1+(rand()%Dice);
        return -damage;
		}
    }

	void AddGold(int amount, int bonus)
	{
		Gold = Gold + amount * bonus;
		std::cout << "Recieved: "<< amount << " gold.\n";
		std::cout << "Total gold: " << Gold;
	};

	void Present() override
    {        
        std::cout << Name << " Hp:" << HealthPoints << "/" << MaxHealthPoints << "\n";
    } 

	bool ManageBackpack(std::string index, int amount)
	{
		if ( backpack.find(index) == backpack.end() )
		{
			std::cout << "Error no item: " << index;		
			return false;
		}
		
		int& temp = backpack[index] ;
		if (temp + amount < 0)
		{
			std::cout << "Not enough " << index;
			return false;
		}
		else
		{
			temp += amount;
			return true;
		}		
	};

	void PresentBackpack()
	{
		int i = 1;
		for (auto const &temp : backpack)
		{
			std::cout << i <<") " << temp.first << ": " << temp.second << "\n";
			i++;
    	}
	}

	int ReturnStats(char i)
	{
		switch(i)
		{
		case('G'):
			return Gold;
			break;
		case('H'):
			return HealthPoints;
			break;
		case('D'):
			return Dice;
			break;	
		}
		return -1;
	}	

	bool usePotion(int i)
	{
		switch(i)
		{
			case(0):			
				if (ManageBackpack("PotionOfHealing", -1))
				{
					AffectHealth(30);
					return true;
				}
				else return false;
				break;
			case(1):
			if (ManageBackpack("PotionOfStrength", -1))
				{
					buffed = true;
					return true;
				}
				else return false;
				break;
		}
		return false;
	} 
private:
	bool isDead = false;
	bool buffed = false;
	std::string Name = "BezImienny";
	int HealthPoints = 50;
	int MaxHealthPoints = 50;	
	int Dice = 12;	
	int Gold = 100;
	std::map<std::string, int> backpack
	{		
		{"PotionOfHealing" , 1},
		{"PotionOfStrength", 2},
	};
};