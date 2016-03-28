#pragma once
#include "CollidableObject.h"
#include "Vector2Normalizer.h"
#include <Thor\Animations.hpp>

using namespace thor;

class CharacterObject :
	public CollidableObject
{
public:
	const float maxSpeed = 50.f;
	float healthPoints, defencePoints, damagePoints, damageRange;
	Animator<Sprite, string> animController;
	FrameAnimation animUp, animDown, animLeft, animRight;

	CharacterObject(Texture& texture, Vector2f position, float healthPoints, float damagePoints, float defencePoints, float damageRange);
	~CharacterObject();	

	void Attack(CharacterObject& character);
	void TakeDamage(float& characterDamage);
};

