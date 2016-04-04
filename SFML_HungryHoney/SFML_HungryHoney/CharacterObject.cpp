#include "stdafx.h"
#include "CharacterObject.h"

CharacterObject::CharacterObject()
{
	maxSpeed = 50.0f;
}

CharacterObject::CharacterObject(Texture & texture, Vector2f position, float scale, float healthPoints, float defencePoints, float damagePoints, float damageRange)
	: CollidableObject(texture, position, scale)
{
	maxSpeed = 50.0f;
	CharacterObject::healthPoints = healthPoints;
	CharacterObject::defencePoints = defencePoints;
	CharacterObject::damagePoints = damagePoints;
	CharacterObject::damageRange = damageRange;
}

CharacterObject::~CharacterObject()
{
}

void CharacterObject::Attack(CharacterObject& character)
{
	float distance = Vector2Extender::NormalizeFloat(objPosition, character.objPosition);
	if (distance < damageRange) {
		character.TakeDamage(damagePoints);
	}
}

void CharacterObject::TakeDamage(float& characterDamage)
{
	float recievingDamage = (characterDamage - defencePoints);
	if (recievingDamage > 0) {
		healthPoints = (healthPoints - recievingDamage);
		cout << "I was attacked! HP:" << healthPoints << endl;
	}
}
