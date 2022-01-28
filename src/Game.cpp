#include "Game.h"
#include "../scenes/TitleCard.h"

Game::Game()
{
	player = new Player();	
	sceneName = "TitleCard";
}

void Game::Run()
{	
	player->AssignName();
	
	while (running)	
	{
		changeScene();		
		currentScene->Present();		
		currentScene->Render();
		sceneName = currentScene->ManageInput();			
	} 
}

//stop the game
void Game::Exit()
{

	std::cout << "\nGoodbye...\n";
	std::cin.ignore();
	running = false;
}

void Game::changeScene()
{
	srand(time(0));
	int rando = (rand()%100);
	if (rando <= 100 && flag)
	{
		CombatMngr mgr(player);
		mgr.Run();
	}
	if (sceneName == "Exit")
		Exit();	
				
	if (sceneName == "JunkYard")
		flag = true;
	 
	
	if ( sceneMap.find(sceneName) == sceneMap.end() ) {
		std::cout << "Error no scene: " << sceneName;
		Exit();
	} else {
	currentScene = sceneMap[sceneName];	
	}
	
}


