#include "stdafx.h"
#include "BeeCharacter.h"


BeeCharacter::BeeCharacter()
{
	fPursuitRange = 0;
	fMaxSpeed = 0;
	fHealthPoints = 0;
	fDamagePoints = 0;
	fAttackRange = 0;
	healthbarScale = 1;
}
BeeCharacter::BeeCharacter(Texture * charachterTexture, Vector2f position, SoundBuffer * bufHit, float maxSpeed, float healthPoints, float damagePoints, float attackRange, float pursuitRange, Texture * healthbarTexture, FloatRect spawnArea)
	:Character(charachterTexture, position, bufHit)
{
	fMaxSpeed = maxSpeed;
	fConstAngle = maxSpeed / 10;
	fHealthPoints = healthPoints;
	fDamagePoints = damagePoints;
	fAttackRange = attackRange;
	fPursuitRange = pursuitRange;
	oldPos = position;
	center = Vector2f(position.x,position.y-fRadius);
	attackTimer = Time(seconds(3));
	if (healthbarTexture != NULL) {
		healthbarScale = sprtCharacter.getLocalBounds().width / 40;
		sprtHealthBar.setTexture(*healthbarTexture);
		sprtHealthBar.setOrigin(sprtHealthBar.getLocalBounds().width / 2, sprtHealthBar.getLocalBounds().height / 2);
		SetHealthbar();
	}

	fMaxHP = healthPoints;
	BeeCharacter::respawnArea = spawnArea;
}
BeeCharacter::~BeeCharacter()
{
}

void BeeCharacter::Update(PlayerCharacter * player)
{
	Character::Update();
		float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), player->sprtCharacter.getPosition());
		if (distance < fAttackRange) {
			velocity = Vector2f(0, 0);
			Attack(player);
		}
		else {
			Move(player);
		}
	SetHealthbar();
	if (bIsDead) {
		Vector2f newPos = Vector2Extender::RandomVectorCoords(respawnArea);
		if (newPos != oldPos) {
			fHealthPoints = fMaxHP;
			sprtCharacter.setPosition(newPos);
			oldPos = newPos;
			bIsDead = false;
		}
	}
}
void BeeCharacter::Draw(RenderWindow & window)
{
	Character::Draw(window);
	window.draw(sprtHealthBar);
}
void BeeCharacter::Move(PlayerCharacter * player)
{
	float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), player->sprtCharacter.getPosition());
	if (distance < fPursuitRange) 
	{
		Vector2f direction = Vector2Extender::NormalizeVector(sprtCharacter.getPosition(), player->sprtCharacter.getPosition());
		velocity = Vector2f(direction.x*-fMaxSpeed, direction.y*-fMaxSpeed);
		center = sprtCharacter.getPosition();
		center.y -= fRadius;
	}
	else 
	{
		velocity = Vector2f(0, 0);

		Vector2f newPos = sprtCharacter.getPosition();
		newPos.x = center.x + sin(fAngle)*fRadius;
		newPos.y = center.y + cos(fAngle)*fRadius;
		sprtCharacter.setPosition(newPos);

		fAngle += fConstAngle;
		if (fAngle > fMaxAngle) { fAngle = 0; }
	}
	Character::Move();
}

void BeeCharacter::Attack(PlayerCharacter * player)
{
	Character::Attack(player);
}

void BeeCharacter::SetHealthbar()
{
	sprtHealthBar.setScale(fHealthPoints*healthbarScale/10, healthbarScale);
	Vector2f position = sprtCharacter.getPosition();
	position.y -= sprtHealthBar.getLocalBounds().height;
	position.x += (sprtCharacter.getLocalBounds().width / 2) - (sprtHealthBar.getLocalBounds().width / 2);
	sprtHealthBar.setPosition(position);
}
