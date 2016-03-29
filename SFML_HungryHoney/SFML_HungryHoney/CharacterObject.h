#pragma once
#include "CollidableObject.h"

class CharacterObject :
	public CollidableObject
{
public:
	const float maxSpeed = 50.f;
	float healthPoints, defencePoints, damagePoints, damageRange;

	CharacterObject(Texture& texture, Vector2f position, float scale, float healthPoints, float damagePoints, float defencePoints, float damageRange);
	~CharacterObject();	

	void Attack(CharacterObject& character);
	void TakeDamage(float& characterDamage);
};

