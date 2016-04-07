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
#include "HUD.h"

using namespace sf;
using namespace std;

const Vector2i windowSize(800, 600);
const string dirSprite = "D:/GitHub/HungryHoney/SFML_HungryHoney2/Debug/Resources/Sprites/", dirLevel = "D:/GitHub/HungryHoney/SFML_HungryHoney2/Debug/Resources/Levels/", dirFont = "D:/GitHub/HungryHoney/SFML_HungryHoney2/Debug/Resources/Fonts/";

Texture txtrBackground1, txtrBackground2, txtrPlayer, txtrBee, txtrSuit, txtrWeapon, txtrHive, txtrInteract, txtrHealthBar, txtrHealth, txtrShield;
Font fontHud;
float beeSpeed = 1, beeHP = 40, beeDamP = 20, beeAttackRange = 32, beePursuitRange = 160;
float plrSpeed = 2, plrHP = 100, plrDefP = 0, plrDamP = 5, plrAttackRange = 16;
Sprite sprtBackground;
PlayerCharacter pcPlayer;
vector<Character*> bees;
Vector2f beeLoc;
BeeCharacter bcBee1, bcBee2, bcBee3, bcBee4, bcBee5, bcBee6;
SuitPickup spBathRobe;
WeaponPickup wpSmoker;
BeehivePickup bpHive;
HUD mainHud;

void SpawnBee(int beeCount);

int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();

	//creates the window where te magic happens
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Hungry Honey - By Geert Cocu");
	window.setFramerateLimit(60);

	View mainView(FloatRect(0,0,windowSize.x,windowSize.y));
	//mainView.zoom(0.5f);
	//Background
	if (txtrBackground1.loadFromFile(dirLevel + "sample_indoor.png")) {
		txtrBackground2.loadFromFile(dirLevel + "sample_map.png");
		sprtBackground.setTexture(txtrBackground1);
		SpriteExtender::SetCenter(&sprtBackground, windowSize.x / 2, windowSize.y / 2);
	}
	//player
	if (txtrPlayer.loadFromFile(dirSprite + "playerBody.png")) {
		pcPlayer = PlayerCharacter(&txtrPlayer, Vector2f(0, 0), &txtrSuit, &txtrWeapon, plrSpeed, plrHP, plrDefP, plrDamP, plrAttackRange);
	}
	//pickups
	if (txtrInteract.loadFromFile(dirSprite + "letter_E_small.png")) {
		if (txtrSuit.loadFromFile(dirSprite + "bathrobe.png")) {
			spBathRobe = SuitPickup(&txtrSuit, &txtrInteract, Vector2f(windowSize.x / 2 + 100, windowSize.y / 2), 20, 5);
		}
		if (txtrWeapon.loadFromFile(dirSprite + "smoker.png")) {
			wpSmoker = WeaponPickup(&txtrWeapon, &txtrInteract, Vector2f(windowSize.x / 2, windowSize.y / 2-100), 20, 20, 40);
		}
		if (txtrHive.loadFromFile(dirSprite + "chest.png")) {
			bpHive = BeehivePickup(&txtrHive, &txtrInteract, Vector2f(windowSize.x / 2 - 100, windowSize.y / 2), 30, Vector2i(100, 100));
		}
	}

	//hud
	if (txtrHealth.loadFromFile(dirSprite + "health.png") && txtrShield.loadFromFile(dirSprite + "shield.png") && fontHud.loadFromFile(dirFont + "kenpixel_square.ttf")) {
		mainHud = HUD(&pcPlayer, &mainView, 60, &txtrHealth, &txtrShield, &fontHud);
	}

	//bee
	if (txtrBee.loadFromFile(dirSprite + "bee.png")) {
		txtrHealthBar.loadFromFile(dirSprite + "healthbar.png");
		bcBee1 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(windowSize, false), beeSpeed, beeHP, beeDamP, beeAttackRange, beePursuitRange, &txtrHealthBar);
		bees.push_back(&bcBee1);
		bcBee2 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(windowSize, false), beeSpeed, beeHP, beeDamP, beeAttackRange, beePursuitRange, &txtrHealthBar);
		bees.push_back(&bcBee2);
		bcBee3 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(windowSize, false), beeSpeed, beeHP, beeDamP, beeAttackRange, beePursuitRange, &txtrHealthBar);
		bees.push_back(&bcBee3);
		bcBee4 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(windowSize, false), beeSpeed, beeHP, beeDamP, beeAttackRange, beePursuitRange, &txtrHealthBar);
		bees.push_back(&bcBee4);
		bcBee5 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(windowSize, false), beeSpeed, beeHP, beeDamP, beeAttackRange, beePursuitRange, &txtrHealthBar);
		bees.push_back(&bcBee5);
		bcBee6 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(windowSize, false), beeSpeed, beeHP, beeDamP, beeAttackRange, beePursuitRange, &txtrHealthBar);
		bees.push_back(&bcBee6);
	}
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		pcPlayer.Update(bees);
		for each (BeeCharacter* bee in bees)
		{
			bee->Update(&pcPlayer);
		}
		spBathRobe.Update(&pcPlayer);
		wpSmoker.Update(&pcPlayer);
		bpHive.Update(&pcPlayer);
		mainView.setCenter(SpriteExtender::GetCenter(&pcPlayer.sprtCharacter));
		mainHud.Update();

		window.clear();
		window.draw(sprtBackground);
		bpHive.Draw(window);
		spBathRobe.Draw(window);
		wpSmoker.Draw(window);

		pcPlayer.Draw(window);
		for each (BeeCharacter* bee in bees)
		{
			bee->Draw(window);
		}
		window.setView(mainView);
		mainHud.Draw(window);
		window.display();
	}
    return 0;
}

void SpawnBee(int beeCount) {
	switch (beeCount)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
}
