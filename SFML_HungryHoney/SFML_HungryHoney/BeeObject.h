#pragma once
#include "CharacterObject.h"
#include "PlayerObject.h"

class BeeObject :
	public CharacterObject
{
public:

	float pursuitRange;
	PlayerObject* player;
	Clock cDelayCounter;
	Time tAttackDelay = Time(seconds(5));

	BeeObject();
	BeeObject(Texture& texture, Vector2f position, float scale, float healthPoints, float damagePoints, float defencePoints, float damageRange, PlayerObject* player, float pursuitRange);
	~BeeObject();

	void UpdateObject();
	void CollisionDetection();
};

