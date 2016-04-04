#include "stdafx.h"
#include "BeeObject.h"

BeeObject::BeeObject()
{
	maxSpeed = 25.0f;
}

BeeObject::BeeObject(Texture & texture, Vector2f position, float scale, float healthPoints, float damagePoints, float defencePoints, float damageRange, PlayerObject* player, float pursuitRange)
	: CharacterObject(texture, position, scale, healthPoints, damagePoints, defencePoints, damageRange)
{
	maxSpeed = 25.0f;
	BeeObject::pursuitRange = pursuitRange;
	BeeObject::player = player;
}

BeeObject::~BeeObject()
{
}

void BeeObject::UpdateObject()
{
	CharacterObject::UpdateObject();
	float distance = Vector2Extender::NormalizeFloat(objPosition,player->objPosition);
	if (distance < damageRange) 
	{
		if (cDelayCounter.getElapsedTime().asSeconds() > tAttackDelay.asSeconds()) 
		{
			Attack(*player);
			cout << "Attack!" << endl;
			cDelayCounter.restart();
		}
	}
	else if (distance < pursuitRange) {
		Vector2f vDistance = Vector2Extender::NormalizeVector(objPosition, player->oldPosition);
		objVelocity = Vector2f(vDistance.x*-maxSpeed, vDistance.y*-maxSpeed);
	}
	else {
		objVelocity = Vector2f(0, 0);
		/*Vector2f v = circlePos - objPosition;

		float x = v.x*cos(angle) + v.y*sin(angle);
		float y = v.y*cos(angle) - v.x*sin(angle);
		circlePos = Vector2f(x, y) + center;
		objSprite.setPosition(circlePos);
		cout << "Circles! X:" << x << " Y:" << y << endl;*/
	}
}

void BeeObject::CollisionDetection()
{
}
