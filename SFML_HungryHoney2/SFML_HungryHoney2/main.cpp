// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "GameplayScene.h"
#include "MainMenuScene.h"
#include "GameOverScene.h"
#include "ScoreManager.h"

using namespace sf;
using namespace std;

Vector2i windowSize(1280, 720);
const int frameLimit = 60;

Scene::GameState state(Scene::MAINMENU);
GameplayScene gameplay(&state, &windowSize);
MainMenuScene mainMenu(&state, &windowSize);
GameOverScene gameOver(&state, &windowSize);

int main()
{
	if (gameplay.Initialize() && mainMenu.Initialize() && gameOver.Initialize())
	{
		//Uncomment if you want to hide the console window
		//FreeConsole();

		//creates the window where te magic happens
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Hungry Honey - By Geert Cocu");
		window.setFramerateLimit(frameLimit);
		window.setMouseCursorVisible(false);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			switch (state)
			{
			case Scene::MAINMENU:
				mainMenu.Update(window);
				mainMenu.Draw(window);
				break;
			case Scene::SETTINGS:
				break;
			case Scene::ABOUT:
				break;
			case Scene::GAMEPLAY:
				gameplay.Update(&gameOver);
				gameplay.Draw(window);
				break;
			case Scene::GAMEOVER:
				gameOver.Update(window);
				gameOver.Draw(window);
				break;
			default:
				break;
			}
		}
		return 0;
	}
	else {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "Initializing scenes failed." << endl;
		cout << "Press any key to terminate the game...";
		cin.get();
		return 1;
	}
}
