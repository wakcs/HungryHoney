// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "MainMenuScene.h"
#include "SettingsScene.h"
#include "AboutScene.h"
#include "GameplayScene.h"
#include "GameOverScene.h"
#include "ScoreManager.h"

using namespace sf;
using namespace std;

Vector2i windowSize(1280, 720);
const int updatesPerSecond = 60;
Clock updateClock;
Time updateTimer;


Scene::GameState state(Scene::MAINMENU);
MainMenuScene mainMenu(&state, &windowSize);
SettingsScene settings(&state, &windowSize);
AboutScene about(&state, &windowSize);
GameplayScene gameplay(&state, &windowSize);
GameOverScene gameOver(&state, &windowSize);

int main()
{
	if (mainMenu.Initialize() && settings.Initialize() && about.Initialize() && gameplay.Initialize() && gameOver.Initialize())
	{
		//Uncomment if you want to hide the console window
		//FreeConsole();

		//creates the window where te magic happens
		sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Hungry Honey - By Geert Cocu");
		window.setMouseCursorVisible(false);
		updateTimer = Time(milliseconds(1000 / updatesPerSecond));

		while (window.isOpen())
		{
			//updates at a certain interval
			if (updateClock.getElapsedTime().asMilliseconds() > updateTimer.asMilliseconds()) 
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
					mainMenu.Update(window, &gameplay);
					break;
				case Scene::SETTINGS:
					settings.Update(window);
					break;
				case Scene::ABOUT:
					about.Update(window);
					break;
				case Scene::GAMEPLAY:
					gameplay.Update(window, &gameOver);
					break;
				case Scene::GAMEOVER:
					gameOver.Update(window);
					break;
				}
				updateClock.restart();
			}
			//draws as fast as the framerate
			switch (state)
			{
			case Scene::MAINMENU:
				mainMenu.Draw(window);
				break;
			case Scene::SETTINGS:
				settings.Draw(window);
				break;
			case Scene::ABOUT:
				about.Draw(window);
				break;
			case Scene::GAMEPLAY:
				gameplay.Draw(window);
				break;
			case Scene::GAMEOVER:
				gameOver.Draw(window);
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
