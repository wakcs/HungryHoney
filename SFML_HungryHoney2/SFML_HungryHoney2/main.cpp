// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Vector2Extender.h"
#include "SpriteExtender.h"
#include "PlayerCharacter.h"
#include "BeeCharacter.h"

using namespace sf;
using namespace std;

const Vector2i windowSize(800, 600);
const string dirSprite = "Resources/Sprites/", dirLevel="Resources/Levels/";

int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();

	//creates the window where te magic happens
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Hungry Honey - By Geert Cocu");

	View mainView(FloatRect(0,0,windowSize.x,windowSize.y));
	mainView.zoom(0.5f);
	Texture txtrBackground; 
	Sprite sprtBackground;
	if (txtrBackground.loadFromFile(dirLevel + "sample_indoor.png")) {
		sprtBackground.setTexture(txtrBackground);
		SpriteExtender::SetCenter(&sprtBackground, windowSize.x / 2, windowSize.y / 2);
	}

	Texture txtrBee;
	BeeCharacter bcBee;
	if (txtrBee.loadFromFile(dirSprite + "Bee.png")) {
		bcBee = BeeCharacter(&txtrBee, Vector2f(windowSize.x / 2, windowSize.y / 2));
	}

	PlayerCharacter pcPlayer(&txtrBee, Vector2f(1000, 1000), &txtrBee, &txtrBee, 0, 0, 0, 0, 0);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}/*
		bcBee.Update(&pcPlayer);
		cout << bcBee.sprtCharacter.getPosition().x << "," << bcBee.sprtCharacter.getPosition().y << endl;*/

		window.clear();
		window.draw(sprtBackground);
		bcBee.Draw(window);
		window.setView(mainView);
		window.display();
	}
    return 0;
}

