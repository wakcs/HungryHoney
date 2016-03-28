#pragma once
#include "CharacterObject.h"
#include "PlayerObject.h"

class BeeObject :
	public CharacterObject
{
public:

	const float maxSpeed = 25.f;
	float pursuitRange;
	PlayerObject& player;
	BeeObject(Texture& texture, Vector2f position, float healthPoints, float damagePoints, float defencePoints, float damageRange, PlayerObject& player, float pursuitRange);
	~BeeObject();

	void UpdateObject();
	void CollisionDetection();
};

