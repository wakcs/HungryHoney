// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "CollidableObject.h"
#include "PlayerObject.h"
#include "BeeObject.h"
#include "Beehive.h"
#include "Hud.h"
#include <list>

using namespace sf;
using namespace std;

enum GameState {
	MAINMENU,
	INTRO,
	GAMEPLAY,
	PAUSE,
	CREDITS
};

Vector2f windowSize(800, 600);
const string windowTitle = "Hungry Honey";
const int frameLimit = 60;
const float viewScale = 5;
GameState gameState = GameState(GAMEPLAY);

list<CollidableObject*> obstructions;
const int beehiveAmount = 3;
list<GameObject> backgroundList;
const Vector2i mapSize(8000, 8000);
const Vector2i blockSize(400, 400);
const int scale = 25;
const int rectSize = 16;
Texture txtrGrass, objTexture, suitTexture, weaponTexture, txtrBeehive, txtrInteract, txtrHealth;
Image imgSheet, imgSun;
Font hudFont;


int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();
	//creates the window where te magic happens
	RenderWindow window(VideoMode(windowSize.x,windowSize.y), windowTitle);
	window.setFramerateLimit(frameLimit);
	//2D Camera
	View mainView(FloatRect(Vector2f(0,0), windowSize));
	mainView.zoom(viewScale);

	//BACKGROUND, WILL CHANGE TO TMXPARSER
	if (!imgSheet.loadFromFile("roguelikeSheet.png")) {
		return 1;
	}
	txtrGrass.loadFromImage(imgSheet, IntRect(85, 0, rectSize, rectSize));
	for (int x = -(mapSize.x / 2) - blockSize.x; x < (mapSize.x / 2) + blockSize.x; x += blockSize.x)
	{
		for (int y = -(mapSize.y / 2) - blockSize.y; y < (mapSize.y / 2) + blockSize.y; y += blockSize.y)
		{
			GameObject background(txtrGrass, Vector2f(x, y), scale);
			backgroundList.push_back(background);
		}
	}
	objTexture.loadFromFile("SFML-Vector.png");
	PlayerObject player(objTexture, Vector2f(0, 0), 1, suitTexture, weaponTexture, 10, 0, 0, 50, mainView);
	BeeObject bee(objTexture, Vector2f(800, 800), 0.5f, 2, 0, 2, 400, player, 1000);

	txtrBeehive.loadFromFile("chest.png");
	txtrInteract.loadFromFile("letter_E.png");
	
	for (size_t i = 0; i < beehiveAmount; i++)
	{
		obstructions.push_back(new Beehive(txtrBeehive, Vector2Extender::RandomVectorCoords(Vector2i(2000, 2000), true), 25, txtrInteract, mapSize, 400, player));
	}

	txtrHealth.loadFromFile("HealthBar.png");
	hudFont.loadFromFile("arial.ttf");		
	Hud mainHud(txtrHealth, imgSun, hudFont, player, Time(seconds(120)), windowSize);

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		switch (gameState)
		{
		case MAINMENU:
			break;
		case INTRO:
			break;
		case GAMEPLAY:
			window.setView(mainView);
			mainHud.UpdateHud(mainView);
			player.UpdateObject();
			bee.UpdateObject();
			if (Mouse::isButtonPressed(player.mbShoot)) {
				//player.Attack(nearest bee)
			}
			for each (GameObject background in backgroundList)
			{
				background.DrawObject(window);
			}
			for each (CollidableObject* object in obstructions)
			{
				player.CollisionDetect(object);
				object->UpdateObject();
				object->DrawObject(window);
			}
			/*player.CollisionDetect(beehive1);
			player.CollisionDetect(beehive2);
			beehive1.UpdateObject();
			beehive2.UpdateObject();
			beehive1.DrawObject(window);
			beehive2.DrawObject(window);*/
			player.DrawObject(window);
			bee.DrawObject(window);
			mainHud.DrawHud(window);
			break;
		case PAUSE:
			break;
		case CREDITS:
			break;
		default:
			break;
		}
		window.display();
	}
    return 0;
}