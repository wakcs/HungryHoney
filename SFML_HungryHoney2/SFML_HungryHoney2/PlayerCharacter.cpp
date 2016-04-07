#include "stdafx.h"
#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter()
{
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(0, 0);
	fScore = 0;
}
PlayerCharacter::PlayerCharacter(Texture * charachterTexture, Vector2f position, Texture * suitTexture, Texture * weaponTexture, float maxSpeed, float healthPoints, float defencePoints, float damagePoints, float attackRange)
	:Character(charachterTexture, position)
{
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(12, 0);
	fScore = 0;

	sprtSuit.setTexture(*suitTexture);
	sprtWeapon.setTexture(*weaponTexture);
	sprtSuit.setPosition(position + suitOffset);
	sprtWeapon.setPosition(position + weaponOffset);

	PlayerCharacter::fMaxSpeed = maxSpeed;
	PlayerCharacter::fHealthPoints = healthPoints;
	PlayerCharacter::fDefencePoints = defencePoints;
	PlayerCharacter::fDamagePoints = damagePoints;
	PlayerCharacter::fAttackRange = attackRange;

	attackTimer = Time(seconds(1));
}
PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Update(vector<Character*> enemys)
{
	Character::Update();
	Move();
	if (Mouse::isButtonPressed(mbShoot)) {
		float smallestDistance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), enemys.front()->sprtCharacter.getPosition());
		int enemyInArray = 0;

		for (int i = 0; i < enemys.size(); i++)
		{
			float distance = Vector2Extender::NormalizeFloat(sprtCharacter.getPosition(), enemys.at(i)->sprtCharacter.getPosition());
			if (smallestDistance > distance) {
				smallestDistance = distance;
				enemyInArray = i;
			}
		}
		Attack(enemys.at(enemyInArray));
	}
}
void PlayerCharacter::Draw(RenderWindow & window)
{
	Character::Draw(window);
	window.draw(sprtSuit);
	window.draw(sprtWeapon);
}

float PlayerCharacter::GetDefencePoints()
{
	return fDefencePoints;
}
float PlayerCharacter::GetScore()
{
	return fScore;
}

Keyboard::Key PlayerCharacter::GetInteractKey()
{
	return kbInteract;
}

void PlayerCharacter::SetDefencePoints(float defencePoints)
{
	fDefencePoints = defencePoints;
}
void PlayerCharacter::SetSuit(Sprite suit)
{
	sprtSuit = suit;
}
void PlayerCharacter::SetWeapon(Sprite weapon)
{
	sprtWeapon = weapon;
}
void PlayerCharacter::SetScore(float score)
{
	fScore = score;
}
void PlayerCharacter::AddScore(float points)
{
	fScore += points;
}
void PlayerCharacter::SubtractScore(float points)
{
	fScore -= points;
}

void PlayerCharacter::Move()
{
	if (Keyboard::isKeyPressed(kbUp)) {
		velocity.y = -fMaxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbDown)) {
		velocity.y = fMaxSpeed;
	}
	else {
		velocity.y = 0;
	}

	if (Keyboard::isKeyPressed(kbLeft)) {
		velocity.x = -fMaxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbRight)) {
		velocity.x = fMaxSpeed;
	}
	else {
		velocity.x = 0;
	}
	Character::Move();
	sprtSuit.setPosition(sprtCharacter.getPosition() + suitOffset);
	sprtWeapon.setPosition(sprtCharacter.getPosition() + weaponOffset);
}
void PlayerCharacter::GetHit(float damagePoints)
{
	float actualDamage = damagePoints - fDefencePoints;
	if (actualDamage > 0) {
		fHealthPoints -= actualDamage;
	}
	cout << "Player hit, current HP: " << fHealthPoints << endl;
}
