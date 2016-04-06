#include "stdafx.h"
#include "BeeCharacter.h"


BeeCharacter::BeeCharacter()
{
}
BeeCharacter::BeeCharacter(Texture * charachterTexture, Vector2f position)
	:Character(charachterTexture, position)
{
	iMaxSpeed = 10;
	iHealthPoints = 4;
	iDamagePoints = 1;
	iAttackRange = 20;
	fPursuitRange = 200;
}
BeeCharacter::~BeeCharacter()
{
}

void BeeCharacter::Update(PlayerCharacter * player)
{
	float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), player->sprtCharacter.getPosition());
	if (distance < iAttackRange) {
		velocity = Vector2f(0, 0);
		Attack(player);
	}
	else {
		Move(player);
	}
}
void BeeCharacter::Move(PlayerCharacter * player)
{
	float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), player->sprtCharacter.getPosition());
	if (distance < fPursuitRange) 
	{
		Vector2f direction = Vector2Extender::NormalizeVector(sprtCharacter.getPosition(), player->sprtCharacter.getPosition());
		velocity = Vector2f(direction.x*iMaxSpeed, direction.y*iMaxSpeed);
		center = sprtCharacter.getPosition();
	}
	else 
	{
		velocity = Vector2f(0, 0);

		Vector2f v = circlePos - sprtCharacter.getPosition();
		float x = v.x*cos(fAngle) + v.y*sin(fAngle);
		float y = v.y*cos(fAngle) - v.x*sin(fAngle);
		circlePos = Vector2f(x, y) + center;
		sprtCharacter.setPosition(circlePos);
	}
	Character::Move();
}
