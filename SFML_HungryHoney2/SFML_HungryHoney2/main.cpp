// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "GameplayScene.h"

using namespace sf;
using namespace std;

Vector2i windowSize(800, 600);
const int frameLimit = 60;

Scene::GameState state(Scene::GAMEPLAY);
GameplayScene gameplay(&state, &windowSize);

int main()
{
	if (gameplay.Initialize())
	{
	//Uncomment if you want to hide the console window
	FreeConsole();

	//creates the window where te magic happens
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Hungry Honey - By Geert Cocu");
	window.setFramerateLimit(frameLimit);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			switch (state)
			{
			case Scene::MAINMENU:
				break;
			case Scene::CONTROLS:
				break;
			case Scene::CREDITS:
				break;
			case Scene::GAMEPLAY:
				gameplay.Update();
				gameplay.Draw(window);
				break;
			case Scene::GAMEOVER:
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
