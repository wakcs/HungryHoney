#include "stdafx.h"
#include "PlayerObject.h"

PlayerObject::PlayerObject(Texture & texture, Vector2f position, float scale, Texture & suit, Texture & weapon, float healthPoints, float damagePoints, float defencePoints, float damageRange, View & mainCam)
	: CharacterObject(texture,position, scale, healthPoints,damagePoints, defencePoints, damageRange), mainCam(mainCam)
{
	score = 0;
	PlayerObject::suit.setTexture(suit);
	PlayerObject::suit.setPosition(position + suitOffset);
	PlayerObject::weapon.setTexture(weapon);
	PlayerObject::weapon.setPosition(position + weaponOffset);
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::UpdateObject()
{
	CharacterObject::UpdateObject();
	if (Keyboard::isKeyPressed(kbUp)) {
		objVelocity.y = -maxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbDown)) {
		objVelocity.y = maxSpeed;
	}
	else { 
		objVelocity.y = 0;
	}
	
	if (Keyboard::isKeyPressed(kbLeft)) {
			objVelocity.x = -maxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbRight)) {
		objVelocity.x = maxSpeed;
	}
	else {
		objVelocity.x = 0;
	}
	mainCam.setCenter(oldPosition + Vector2f(objCollider.width / 2, objCollider.height / 2));
}

void PlayerObject::DrawObject(RenderWindow & window)
{
	CharacterObject::DrawObject(window);
	window.draw(suit);
	window.draw(weapon);
}
