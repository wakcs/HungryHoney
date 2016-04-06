#pragma once
#include <SFML\Graphics.hpp>
#include "Vector2Extender.h"

using namespace sf;
using namespace std;

class Character
{
public:
	Sprite sprtCharacter;

	Character();
	Character(Texture* charachterTexture, Vector2f position);
	~Character();

	//called in the update
	void Update();
	void Draw(RenderWindow&window);

	//getters
	int GetMaxSpeed();
	int GetHealthPoints();
	int GetDamagePoints();
	int GetAttackRange();

	//setters
	void SetMaxSpeed(int maxSpeed);
	void SetHealthPoints(int healthPoints);
	void SetDamagePoints(int damagePoints);
	void SetAttackRange(int attackRange);

protected:
	int iMaxSpeed = 0, iHealthPoints = 0, iDamagePoints = 0, iAttackRange = 0;
	Vector2f velocity;

	//attackdelay
	Clock attackCounter;
	Time attackTimer = Time(seconds(0));

	//special actions
	void Move();
	void Attack(Character* character);
	void GetHit(int damagePoints);
};

