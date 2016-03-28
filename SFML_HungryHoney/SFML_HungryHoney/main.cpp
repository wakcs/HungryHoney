// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "CollidableObject.h"
#include "PlayerObject.h"
#include "BeeObject.h"
#include <list>
#include <Thor\Animations.hpp>

using namespace sf;
using namespace std;

const int windowWidth = 800;
const int windowHeight = 600;
const string windowTitle = "Hungry Honey";
const int frameLimit = 60;

list<CollidableObject> obstructions;
list<GameObject> backgroundList;
const float mapWidth = 8000;
const float mapHeight = 8000;

int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();//creates the window where te magic happens
	RenderWindow window(VideoMode(windowWidth, windowHeight), windowTitle);
	window.setFramerateLimit(frameLimit);
	//2D Camera
	View mainView(FloatRect(windowWidth / 2, windowHeight / 2, windowWidth, windowHeight));
	mainView.zoom(5.f);


	Texture objTexture; 
	objTexture.loadFromFile("SFML-Vector.png");
	Texture bgTexture;
	if (bgTexture.loadFromFile("grass.png")) {
		for (float x = -(mapWidth / 2); x < mapWidth / 2; x += 800)
		{
			for (float y = -(mapHeight / 2); y < mapHeight / 2; y += 800)
			{
				cout << "Adding tile cords:" << x << "," << y << endl;
				GameObject background(bgTexture, Vector2f(x, y));
				background.objSprite.setScale(50, 50);
				backgroundList.push_back(background);
			}
		}
	}
	Texture suitTexture;
	Texture weaponTexture;
	CollidableObject heavyObj(objTexture, Vector2f(100, -500));
	CollidableObject lightObj(objTexture, Vector2f(0, 700));
	obstructions.push_back(heavyObj);
	obstructions.push_back(lightObj);
	PlayerObject player(objTexture, Vector2f(0, 0), suitTexture, weaponTexture, 10, 0, 0, 50, mainView);
	BeeObject bee(objTexture, Vector2f(800, 800), 2, 0, 2, 400, player, 1000);

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}
		//update
		/*if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{
			mainView.move(Vector2f(-1,0));
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			mainView.move(Vector2f(1, 0));
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			mainView.move(Vector2f(0, -1));
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			mainView.move(Vector2f(0, 1));
		}
		if (Keyboard::isKeyPressed(Keyboard::LShift)) {
			mainView.zoom(2.f);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			mainView.zoom(0.5f);
		}*/
		player.UpdateObject();
		bee.UpdateObject();
		if (Mouse::isButtonPressed(player.mbShoot)) {
			//player.Attack(nearest bee)
		}
		for each (CollidableObject object in obstructions)
		{
			player.CollisionDetect(object);
			object.UpdateObject();
		}

		//drawing
		window.clear();
		for each (GameObject background in backgroundList)
		{
			background.DrawObject(window);
		}
		heavyObj.DrawObject(window);
		lightObj.DrawObject(window);
		player.DrawObject(window);
		bee.DrawObject(window);
		window.setView(mainView);
		window.display();
	}
    return 0;
}

