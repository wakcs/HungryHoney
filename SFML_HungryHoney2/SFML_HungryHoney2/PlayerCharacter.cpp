#include "stdafx.h"
#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter()
{
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(0, 0);
	iScore = 0;
}
PlayerCharacter::PlayerCharacter(Texture * charachterTexture, Vector2f position, Texture * suitTexture, Texture * weaponTexture, int maxSpeed, int healthPoints, int defencePoints, int damagePoints, int attackRange)
	:Character(charachterTexture, position)
{
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(12, 0);
	iScore = 0;

	sprtSuit.setTexture(*suitTexture);
	sprtWeapon.setTexture(*weaponTexture);
	sprtSuit.setPosition(position + suitOffset);
	sprtWeapon.setPosition(position + weaponOffset);

	PlayerCharacter::iMaxSpeed = maxSpeed;
	PlayerCharacter::iHealthPoints = healthPoints;
	PlayerCharacter::iDefencePoints = defencePoints;
	PlayerCharacter::iDamagePoints = damagePoints;
	PlayerCharacter::iAttackRange = attackRange;
}
PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Update(vector<Character> *enemys)
{
	Move();
	if (enemys != NULL && Mouse::isButtonPressed(mbShoot)) {
		float smallestDistance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), enemys->front().sprtCharacter.getPosition());
		int enemyInArray = 0;

		for (int i = 0; i < enemys->size(); i++)
		{
			float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), enemys->at(i).sprtCharacter.getPosition());
			if (smallestDistance > distance) {
				smallestDistance = distance;
				enemyInArray = i;
			}
		}
		Attack(&enemys->at(enemyInArray));
	}
}
void PlayerCharacter::Draw(RenderWindow & window)
{
	Character::Draw(window);
	window.draw(sprtSuit);
	window.draw(sprtWeapon);
}

int PlayerCharacter::GetDefencePoints()
{
	return iDefencePoints;
}
int PlayerCharacter::GetScore()
{
	return iScore;
}

Keyboard::Key PlayerCharacter::GetInteractKey()
{
	return kbInteract;
}

void PlayerCharacter::SetDefencePoints(int defencePoints)
{
	iDefencePoints = defencePoints;
}
void PlayerCharacter::SetSuit(Sprite suit)
{
	sprtSuit = suit;
}
void PlayerCharacter::SetWeapon( Sprite weapon)
{
	sprtWeapon = weapon;
}
void PlayerCharacter::SetScore(int score)
{
	iScore = score;
}
void PlayerCharacter::AddScore(int points)
{
	iScore += points;
}
void PlayerCharacter::SubtractScore(int points)
{
	iScore -= points;
}

void PlayerCharacter::Move()
{
	if (Keyboard::isKeyPressed(kbUp)) {
		velocity.y = -iMaxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbDown)) {
		velocity.y = iMaxSpeed;
	}
	else {
		velocity.y = 0;
	}

	if (Keyboard::isKeyPressed(kbLeft)) {
		velocity.x = -iMaxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbRight)) {
		velocity.x = iMaxSpeed;
	}
	else {
		velocity.x = 0;
	}
	Character::Move();
	sprtSuit.setPosition(sprtCharacter.getPosition() + suitOffset);
	sprtWeapon.setPosition(sprtCharacter.getPosition() + weaponOffset);
}
void PlayerCharacter::GetHit(int damagePoints)
{
	iHealthPoints -= damagePoints - iDefencePoints;
}
