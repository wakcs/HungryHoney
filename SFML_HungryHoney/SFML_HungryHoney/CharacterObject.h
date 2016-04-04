#pragma once
#include "CollidableObject.h"

class CharacterObject :
	public CollidableObject
{
public:
	float maxSpeed, healthPoints, defencePoints, damagePoints, damageRange;

	CharacterObject();
	CharacterObject(Texture& texture, Vector2f position, float scale, float healthPoints, float damagePoints, float defencePoints, float damageRange);
	~CharacterObject();	

	void Attack(CharacterObject& character);
	void TakeDamage(float& characterDamage);

};

