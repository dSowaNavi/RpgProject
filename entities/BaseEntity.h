#pragma once
#include <iostream>

class BaseEntity
{
public:
	virtual void AffectHealth(int damage) = 0;
	virtual void Update() = 0;
	virtual void Present() =0;
	virtual int RollDamage() =0;
	//virtual void UseSpecial() =0;
	bool shouldPop;
	int HealthPoints;
protected:
	int MaxHealthPoints;
	int Dice;
	std::string Name;	
};