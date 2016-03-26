#pragma once
#include "CharacterObject.h"
#include "PlayerObject.h"

class BeeObject :
	public CharacterObject
{
public:
	const Vector2f center = Vector2f(0, 0);
	Vector2f circlePos = Vector2f(0, 500);
	const float angle = 100;

	float pursuitRange;
	PlayerObject player;
	BeeObject(Texture& texture, Vector2f position, float healthPoints, float damagePoints, float defencePoints, float damageRange, PlayerObject& player, float pursuitRange);
	~BeeObject();

	void UpdateObject();
	void CollisionDetection();
};

