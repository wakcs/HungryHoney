#pragma once
#include "Character.h"
#include "PlayerCharacter.h"

class BeeCharacter :
	public Character
{
public:
	BeeCharacter();
	BeeCharacter(Texture* charachterTexture, Vector2f position, float maxSpeed, float healthPoints, float damagePoints, float attackRange, float pursuitRange, Texture * healhtbarTexture);
	virtual ~BeeCharacter();

	//called in the update
	virtual void Update(PlayerCharacter * player);
	virtual void Draw(RenderWindow & window);

private:
	//fMaxAngle is a rough estimate and changes according the fRadius
	float fPursuitRange, fConstAngle = 0.03f, fAngle = 0, fMaxAngle=6.25f, fRadius = 20, healthbarScale;
	Vector2f center;
	Sprite sprtHealthBar;

	virtual void Move(PlayerCharacter * player);
	virtual void Attack(PlayerCharacter * player);

	void SetHealthbar();
};

