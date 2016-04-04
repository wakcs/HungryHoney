// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
/*#include "GameObject.h"
#include "CollidableObject.h"
#include "PlayerObject.h"
#include "BeeObject.h"
#include "Beehive.h"
#include "Hud.h"
#include <list>*/
#include "Scene.h"
#include "GameplayScene.h"

using namespace sf;
using namespace std;


Vector2f windowSize(1280, 720);
const string windowTitle = "Hungry Honey";
const int frameLimit = 60;
Scene::GameState gameState = Scene::GameState(Scene::GAMEPLAY);

GameplayScene gameplay(&windowSize, &gameState);

int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();
	//creates the window where te magic happens
	RenderWindow window(VideoMode(windowSize.x,windowSize.y), windowTitle);
	window.setFramerateLimit(frameLimit);
	
	gameplay.Initialize();

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		
		switch (gameState)
		{
		case Scene::MAINMENU:
			break;
		case Scene::INTRO:
			break;
		case Scene::GAMEPLAY:
			gameplay.Update();
			gameplay.Draw(window);
			break;
		case Scene::PAUSE:
			break;
		case Scene::CREDITS:
			break;
		default:
			break;
		}
	}
    return 0;
}