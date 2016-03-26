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
	float distance = Vector2Normalizer::NormalizeFloat(objPosition,player.objPosition);
	if (distance < damageRange) {
		Attack(player);
	}
	else if (distance < pursuitRange) {
		objVelocity += Vector2Normalizer::NormalizeVector(objPosition, player.oldPosition);
	}
	else {
		Vector2f v = circlePos - center;

		float x = v.x*cos(angle) + v.y*sin(angle);
		float y = v.y*cos(angle) - v.x*sin(angle);
		circlePos = Vector2f(x, y) + center;
		objSprite.move(circlePos);
		cout << "Circles! X:" << x << " Y:" << y << endl;
	}
}

void BeeObject::CollisionDetection()
{
}
