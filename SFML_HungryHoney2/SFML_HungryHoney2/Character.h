#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Vector2Extender.h"

using namespace sf;
using namespace std;

class Character
{
public:
	Sprite sprtCharacter;

	Character();
	Character(Texture* charachterTexture, Vector2f position);
	virtual ~Character();

	//called in the update
	virtual void Update();
	virtual void Draw(RenderWindow&window);

	//getters
	virtual float GetMaxSpeed();
	virtual float GetHealthPoints();
	virtual float GetDamagePoints();
	virtual float GetAttackRange();
	virtual bool GetDeathState();

	//setters
	virtual void SetMaxSpeed(float maxSpeed);
	virtual void SetHealthPoints(float healthPoints);
	virtual void SetDamagePoints(float damagePoints);
	virtual void SetAttackRange(float attackRange);

protected:
	float fMaxSpeed = 0, fHealthPoints = 0, fDamagePoints = 0, fAttackRange = 0;
	bool bIsDeath = false;
	Vector2f velocity;

	//attackdelay
	Clock attackCounter;
	Time attackTimer = Time(seconds(0));

	//special actions
	virtual void Move();
	virtual void Attack(Character* character);
	virtual void GetHit(float damagePoints);
};

