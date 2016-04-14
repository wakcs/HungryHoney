#include "stdafx.h"
#include "Character.h"


Character::Character()
{
}
Character::Character(Texture * charachterTexture, Vector2f position)
{
	sprtCharacter.setTexture(*charachterTexture);
	sprtCharacter.setOrigin(sprtCharacter.getLocalBounds().width / 2, sprtCharacter.getLocalBounds().height / 2);
	sprtCharacter.setPosition(position);
	bIsDead = false;
}
Character::~Character()
{
}

float Character::GetMaxSpeed()
{
	return fMaxSpeed;
}
float Character::GetHealthPoints()
{
	return fHealthPoints;
}
float Character::GetDamagePoints()
{
	return fDamagePoints;
}
float Character::GetAttackRange()
{
	return fAttackRange;
}

bool Character::IsDead()
{
	return bIsDead;
}

void Character::SetMaxSpeed(float maxSpeed)
{
	fMaxSpeed = maxSpeed;
}
void Character::SetHealthPoints(float healthPoints)
{
	fHealthPoints = healthPoints;
}
void Character::SetDamagePoints(float damagePoints)
{
	fDamagePoints = damagePoints;
}
void Character::SetAttackRange(float attackRange)
{
	fAttackRange = attackRange;
}

void Character::Update()
{
	if (fHealthPoints <= 0) {
		bIsDead = true;
	}
	else {
		bIsDead = false;
	}
}
void Character::Draw(RenderWindow & window)
{
	window.draw(sprtCharacter);
}

void Character::Move()
{
	sprtCharacter.move(velocity);
	Vector2f curScale = sprtCharacter.getScale();
	if (velocity.x < 0) {
		curScale.x = -1;
	}
	else {
		curScale.x = 1;
	}
	sprtCharacter.setScale(curScale);
}
void Character::Attack(Character * character)
{
	float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), character->sprtCharacter.getPosition());
	if (distance < fAttackRange && attackCounter.getElapsedTime().asMilliseconds() > attackTimer.asMilliseconds()) {
		character->GetHit(fDamagePoints);
		attackCounter.restart();
	}
}
void Character::GetHit(float damagePoints)
{
	fHealthPoints -= damagePoints;
	cout << "Character hit, current HP: " << fHealthPoints << endl;
}
