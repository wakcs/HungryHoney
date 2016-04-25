#pragma once
#include "Character.h"
#include "PlayerCharacter.h"

class BeeCharacter :
	public Character
{
public:
	BeeCharacter();
	BeeCharacter(Texture* charachterTexture, Vector2f position, SoundBuffer*bufHit, float maxSpeed, float healthPoints, float damagePoints, float attackRange, float pursuitRange, Texture * healhtbarTexture, FloatRect center);
	virtual ~BeeCharacter();

	//called in the update
	virtual void Update(PlayerCharacter * player);
	virtual void Draw(RenderWindow & window);

private:
	//fMaxAngle is a rough estimate and changes according the fRadius
	float fPursuitRange, fConstAngle = 0, fAngle = 0, fMaxAngle=6.25f, fRadius = 20, healthbarScale, fMaxHP;
	FloatRect respawnArea;
	Vector2f center, oldPos;
	Sprite sprtHealthBar;
	
	virtual void Move(PlayerCharacter * player);
	virtual void Attack(PlayerCharacter * player);

	void SetHealthbar();
};

