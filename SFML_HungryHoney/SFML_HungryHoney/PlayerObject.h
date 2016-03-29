#pragma once
#include "CharacterObject.h"
class PlayerObject :
	public CharacterObject
{
public:
	const Keyboard::Key kbUp = Keyboard::Key::W;
	const Keyboard::Key kbDown = Keyboard::Key::S;
	const Keyboard::Key kbLeft = Keyboard::Key::A;
	const Keyboard::Key kbRight = Keyboard::Key::D;
	const Keyboard::Key kbInteract = Keyboard::Key::E;
	const Mouse::Button mbShoot = Mouse::Button::Left;
	View& mainCam;
	Sprite suit, weapon;
	const Vector2f suitOffset = Vector2f(0,0);
	const Vector2f weaponOffset = Vector2f(50, 50);

	int score = 0;

	PlayerObject(Texture& texture, Vector2f position, float scale, Texture& suit, Texture& weapon, float healthPoints, float damagePoints, float defencePoints, float damageRange, View& mainCam);
	~PlayerObject();	

	void UpdateObject();
	void DrawObject(RenderWindow& window);
};

