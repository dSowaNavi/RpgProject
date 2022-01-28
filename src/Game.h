#pragma once
#include <iostream>
#include <stdio.h>
#include <map>
#include "../include/IncludeScenes.h"
#include "../entities/Player.h"
#include "CombatMngr.h"
#include <ctime>

class Game
{
public:
	Game();
	void Run();
	void Exit();		
	void changeScene();			

private:
Player* player;
bool running = true;
BaseScene* currentScene;
std::string sceneName;
bool flag = false;
std::map<std::string, BaseScene*> sceneMap
{
	{"Begining", new Begining()},
	{"EndScene", new EndScene()},
	{"JunkYard", new JunkYard(player)},
	{"Shop", new Shop(player)},
	{"TitleCard", new TitleCard()},
};

};
