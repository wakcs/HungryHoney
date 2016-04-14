#pragma once
#include "Character.h"

class PlayerCharacter :
	public Character
{
public:
	PlayerCharacter();
	PlayerCharacter(Texture*charachterTexture, Vector2f position, Texture* suitTexture, Texture*weaponTexture, float maxSpeed, float healthPoints, float defencePoints, float damagePoints, float attackRange, FloatRect playBorder);
	~PlayerCharacter();

	//called in the update
	void Update(vector<Character*> enemys);
	void Draw(RenderWindow&window);

	//getters
	float GetDefencePoints();
	float GetScore();
	Keyboard::Key GetInteractKey();

	//setters
	void SetDefencePoints(float defencePoints);
	void SetSuit(Sprite suit);
	void SetWeapon(Sprite weapon);
	void SetScore(float score);
	void AddScore(float points);
	void SubtractScore(float points);
	
private:
	float fDefencePoints, fScore;
	Sprite sprtSuit, sprtWeapon;
	Vector2f suitOffset, weaponOffset;
	FloatRect playBorder;

	//inputs
	Keyboard::Key kbUp = Keyboard::Key::Up;
	Keyboard::Key kbDown = Keyboard::Key::Down;
	Keyboard::Key kbLeft = Keyboard::Key::Left;
	Keyboard::Key kbRight = Keyboard::Key::Right;
	Keyboard::Key kbInteract = Keyboard::Key::E;
	Keyboard::Key kbShoot = Keyboard::Key::Space;

	void Move();
	void GetHit(float damagePoints);
};

