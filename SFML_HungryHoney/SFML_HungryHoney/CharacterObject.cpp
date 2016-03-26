#include "stdafx.h"
#include "CharacterObject.h"
#include "Vector2Normalizer.h"

CharacterObject::CharacterObject(Texture & texture, Vector2f position, float healthPoints, float defencePoints, float damagePoints, float damageRange) : CollidableObject(texture, position)
{
	CharacterObject::healthPoints = healthPoints;
	CharacterObject::defencePoints = defencePoints;
	CharacterObject::damagePoints = damagePoints;
	CharacterObject::damageRange = damageRange;
}

CharacterObject::~CharacterObject()
{
}

void CharacterObject::Attack(CharacterObject character)
{
	float distance = Vector2Normalizer::NormalizeFloat(objPosition, character.objPosition);
	if (distance < damageRange) {
		character.TakeDamage(this);
	}
}

void CharacterObject::TakeDamage(CharacterObject* character)
{
	float recievingDamage = (character->damagePoints - defencePoints);
	if (recievingDamage > 0) {
		healthPoints -= recievingDamage;
	}
	cout << "I was attacked! HP:" << healthPoints << endl;
}