#include "stdafx.h"
#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter()
{
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(0, 0);
	fScore = 0;
}
PlayerCharacter::PlayerCharacter(Texture * charachterTexture, Vector2f position, Texture * suitTexture, Texture * weaponTexture, float maxSpeed, float healthPoints, float defencePoints, float damagePoints, float attackRange, FloatRect playBorder)
	:Character(charachterTexture, position)
{
	suitOffset = Vector2f(0, 0);
	weaponOffset = Vector2f(12, 0);
	fScore = 0;
	if (suitTexture != NULL) {
		sprtSuit.setTexture(*suitTexture);
	}
	if (weaponTexture != NULL) {
		sprtWeapon.setTexture(*weaponTexture);
	}
	sprtSuit.setPosition(position + suitOffset);
	sprtWeapon.setPosition(position + weaponOffset);

	PlayerCharacter::fMaxSpeed = maxSpeed;
	PlayerCharacter::fHealthPoints = healthPoints;
	PlayerCharacter::fDefencePoints = defencePoints;
	PlayerCharacter::fDamagePoints = damagePoints;
	PlayerCharacter::fAttackRange = attackRange;

	attackTimer = Time(seconds(1)); 
	PlayerCharacter::playBorder = playBorder;
}
PlayerCharacter::~PlayerCharacter()
{
}

void PlayerCharacter::Update(vector<Character*> enemys)
{
	Character::Update();
	Move();
	if (Keyboard::isKeyPressed(kbShoot)) {
		for (int i = 0; i < enemys.size(); i++)
		{
			Attack(enemys.at(i));
		}
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
	Vector2f charPos = sprtCharacter.getPosition();
	if (Keyboard::isKeyPressed(kbUp) && charPos.y > playBorder.top)
	{
		velocity.y = -fMaxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbDown) && charPos.y < playBorder.top + playBorder.height) {
		velocity.y = fMaxSpeed;
	}
	else {
		velocity.y = 0;
	}

	if (Keyboard::isKeyPressed(kbLeft) && charPos.x > playBorder.left) {
		velocity.x = -fMaxSpeed;
	}
	else if (Keyboard::isKeyPressed(kbRight) && charPos.x < playBorder.left + playBorder.width) {
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
