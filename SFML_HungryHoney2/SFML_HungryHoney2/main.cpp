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
#include "SuitPickup.h"
#include "WeaponPickup.h"
#include "BeehivePickup.h"

using namespace sf;
using namespace std;

const Vector2i windowSize(800, 600);
const string dirSprite = "D:/GitHub/HungryHoney/SFML_HungryHoney2/Debug/Resources/Sprites/", dirLevel = "D:/GitHub/HungryHoney/SFML_HungryHoney2/Debug/Resources/Levels/", dirFont = "D:/GitHub/HungryHoney/SFML_HungryHoney2/Debug/Resources/Fonts/";

Texture txtrBackground1, txtrBackground2, txtrPlayer, txtrSuitNaked, txtrSuitRobe, txtrWeaponNone, txtrWeaponSmoker, txtrHive, txtrInteract;
Sprite sprtBackground;
PlayerCharacter pcPlayer;
SuitPickup spBathRobe;
WeaponPickup wpSmoker;
BeehivePickup bpHive;

Font hudFont;
Text txtScore;

int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();

	//creates the window where te magic happens
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Hungry Honey - By Geert Cocu");
	window.setFramerateLimit(60);

	View mainView(FloatRect(0,0,windowSize.x,windowSize.y));
	mainView.zoom(0.5f);
	//Background
	if (txtrBackground1.loadFromFile(dirLevel + "sample_indoor.png")) {
		txtrBackground2.loadFromFile(dirLevel + "sample_map.png");
		sprtBackground.setTexture(txtrBackground1);
		SpriteExtender::SetCenter(&sprtBackground, windowSize.x / 2, windowSize.y / 2);
	}
	//player
	if (txtrPlayer.loadFromFile(dirSprite + "playerBody.png")) {
		pcPlayer = PlayerCharacter(&txtrPlayer, Vector2f(windowSize.x / 2, windowSize.y / 2), &txtrSuitNaked, &txtrWeaponNone, 2, 10, 0, 1, 20);
	}
	//pickups
	if (txtrInteract.loadFromFile(dirSprite + "letter_E_small.png")) {
		if (txtrSuitRobe.loadFromFile(dirSprite + "bathrobe.png")) {
			spBathRobe = SuitPickup(&txtrSuitRobe, &txtrInteract, Vector2f(windowSize.x / 2 + 100, windowSize.y / 2), 20, 2);
		}
		if (txtrWeaponSmoker.loadFromFile(dirSprite + "smoker.png")) {
			wpSmoker = WeaponPickup(&txtrWeaponSmoker, &txtrInteract, Vector2f(windowSize.x / 2, windowSize.y / 2-100), 20, 3, 40);
		}
		if (txtrHive.loadFromFile(dirSprite + "chest.png")) {
			bpHive = BeehivePickup(&txtrHive, &txtrInteract, Vector2f(windowSize.x / 2 - 100, windowSize.y / 2), 30, Vector2i(100, 100));
		}
	}

	//hud
	if (hudFont.loadFromFile(dirFont + "kenpixel_square.ttf")) {
		txtScore.setFont(hudFont);
		txtScore.setPosition(windowSize.x / 2 - 100, windowSize.y / 2 - 200);
	}

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pcPlayer.Update(NULL);
		spBathRobe.Update(&pcPlayer);
		wpSmoker.Update(&pcPlayer);
		bpHive.Update(&pcPlayer);
		txtScore.setString("Score: " + to_string(pcPlayer.GetScore()));
		if (Keyboard::isKeyPressed(Keyboard::Key::Y)) {
			sprtBackground.setTexture(txtrBackground2);
		}

		window.clear();
		window.draw(sprtBackground);
		bpHive.Draw(window);
		spBathRobe.Draw(window);
		wpSmoker.Draw(window);

		pcPlayer.Draw(window);
		window.setView(mainView);
		window.draw(txtScore);
		window.display();
	}
    return 0;
}

