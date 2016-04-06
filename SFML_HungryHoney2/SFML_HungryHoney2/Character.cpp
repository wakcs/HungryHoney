#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}
Character::Character(Texture * charachterTexture, Vector2f position)
{
	sprtCharacter.setTexture(*charachterTexture);
	sprtCharacter.setPosition(position);
}
Character::~Character()
{
}

int Character::GetMaxSpeed()
{
	return iMaxSpeed;
}
int Character::GetHealthPoints()
{
	return iHealthPoints;
}
int Character::GetDamagePoints()
{
	return iDamagePoints;
}
int Character::GetAttackRange()
{
	return iAttackRange;
}

void Character::SetMaxSpeed(int maxSpeed)
{
	iMaxSpeed = maxSpeed;
}
void Character::SetHealthPoints(int healthPoints)
{
	iHealthPoints = healthPoints;
}
void Character::SetDamagePoints(int damagePoints)
{
	iDamagePoints = damagePoints;
}
void Character::SetAttackRange(int attackRange)
{
	iAttackRange = attackRange;
}

void Character::Update()
{
}
void Character::Draw(RenderWindow & window)
{
	window.draw(sprtCharacter);
}

void Character::Move()
{
	sprtCharacter.move(velocity);
}
void Character::Attack(Character * character)
{
	float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), character->sprtCharacter.getPosition());
	if (distance < iAttackRange && attackCounter.getElapsedTime().asMilliseconds() > attackTimer.asMilliseconds()) {
		character->GetHit(iDamagePoints);
		attackCounter.restart();
	}
}
void Character::GetHit(int damagePoints)
{
	iHealthPoints -= damagePoints;
}
