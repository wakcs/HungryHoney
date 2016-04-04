#pragma once
#include "CharacterObject.h"
class PlayerObject :
	public CharacterObject
{
public:
	Keyboard::Key kbUp, kbDown, kbLeft, kbRight, kbInteract;
	Mouse::Button mbShoot;
	View* mainCam;
	Sprite suit, weapon;
	Vector2f suitOffset, weaponOffset;

	int score = 0;

	PlayerObject();
	PlayerObject(Texture& texture, Vector2f position, float scale, Texture& suit, Texture& weapon, float healthPoints, float damagePoints, float defencePoints, float damageRange, View* mainCam);
	~PlayerObject();	

	void UpdateObject();
	void DrawObject(RenderWindow& window);
};

