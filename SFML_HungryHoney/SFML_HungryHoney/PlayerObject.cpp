#include "stdafx.h"
#include "PlayerObject.h"

PlayerObject::PlayerObject()
{
	kbUp = Keyboard::Key::W;
	kbDown = Keyboard::Key::S;
	kbLeft = Keyboard::Key::A;
	kbRight = Keyboard::Key::D;
	kbInteract = Keyboard::Key::E;
	mbShoot = Mouse::Button::Left;
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(50, 50);
}

PlayerObject::PlayerObject(Texture & texture, Vector2f position, float scale, Texture & suit, Texture & weapon, float healthPoints, float damagePoints, float defencePoints, float damageRange, View* mainCam)
	: CharacterObject(texture,position, scale, healthPoints,damagePoints, defencePoints, damageRange)
{
	kbUp = Keyboard::Key::W;
	kbDown = Keyboard::Key::S;
	kbLeft = Keyboard::Key::A;
	kbRight = Keyboard::Key::D;
	kbInteract = Keyboard::Key::E;
	mbShoot = Mouse::Button::Left;
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(50, 50);
	PlayerObject::mainCam = mainCam;
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
	suit.setPosition(objPosition + suitOffset);
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
	mainCam->setCenter(oldPosition + Vector2f(objCollider.width / 2, objCollider.height / 2));
}

void PlayerObject::DrawObject(RenderWindow & window)
{
	CharacterObject::DrawObject(window);
	window.draw(suit);
	window.draw(weapon);
}

void PlayerObject::CollisionDetect(CollidableObject * object)
{
	if (objCollider.intersects(object->objCollider)) {
		cout << "oldPos" << objPosition.x << "," << objPosition.y << endl;;
		if (Keyboard::isKeyPressed(kbUp) || Keyboard::isKeyPressed(kbDown) || fabs(objVelocity.y) > 0) {
			objPosition.y = oldPosition.y;
		}
		if (Keyboard::isKeyPressed(kbLeft) || Keyboard::isKeyPressed(kbRight) || fabs(objVelocity.x) > 0) {
			objPosition.x = oldPosition.x;
		}
		cout << "newPos" << objPosition.x << "," << objPosition.y << endl;;
		objSprite.setPosition(objPosition);
	}
}
