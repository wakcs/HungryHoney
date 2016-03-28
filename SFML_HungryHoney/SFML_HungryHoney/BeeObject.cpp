#include "stdafx.h"
#include "BeeObject.h"

BeeObject::BeeObject(Texture & texture, Vector2f position, float healthPoints, float damagePoints, float defencePoints, float damageRange, PlayerObject& player, float pursuitRange)
	: CharacterObject(texture,position,healthPoints,damagePoints,defencePoints,damageRange), player(player)
{
	BeeObject::pursuitRange = pursuitRange;
}

BeeObject::~BeeObject()
{
}

void BeeObject::UpdateObject()
{
	CharacterObject::UpdateObject();
	float distance = Vector2Normalizer::NormalizeFloat(objPosition,player.objPosition);
	if (distance < damageRange) {
		Attack(player);
		cout << "Attack!" << endl;
	}
	else if (distance < pursuitRange) {
		Vector2f vDistance = Vector2Normalizer::NormalizeVector(objPosition, player.oldPosition);
		objVelocity = Vector2f(vDistance.x*-maxSpeed, vDistance.y*-maxSpeed);
		cout << "Follow! vel X:" << objVelocity.x << " Y:" << objVelocity.y << endl;
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
