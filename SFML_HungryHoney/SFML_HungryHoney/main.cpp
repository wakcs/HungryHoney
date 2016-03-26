// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "CollidableObject.h"

using namespace sf;
using namespace std;

const int windowWidth = 800;
const int windowHeight = 600;
const string windowTitle = "Hungry Honey";
const int frameLimit = 60;
int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();
	//creates the window where te magic happens
	RenderWindow window(VideoMode(windowWidth, windowHeight), windowTitle);
	window.setFramerateLimit(frameLimit);
	//2D Camera
	View mainView(FloatRect(windowWidth / 2, windowHeight / 2, windowWidth, windowHeight));
	mainView.zoom(5.f);

	Texture objTexture;
	objTexture.loadFromFile("D:\\Downloads\\SFML-Vector.png");
	objTexture.setSmooth(true);
	CollidableObject heavyObj(objTexture, Vector2f(100, -500));
	CollidableObject lightObj(objTexture, Vector2f(0, 700));

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

		}
		//update
		if (Keyboard::isKeyPressed(Keyboard::Left)) 
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
		}
		heavyObj.CollisionDetect(lightObj);
		heavyObj.UpdateObject();
		heavyObj.objVelocity = Vector2f(0, 5);
		lightObj.UpdateObject();
		//drawing
		window.clear();
		heavyObj.DrawObject(window);
		lightObj.DrawObject(window);
		window.setView(mainView);
		window.display();
	}
    return 0;
}

