#pragma once
#include "Character.h"

class PlayerCharacter :
	public Character
{
public:
	PlayerCharacter();
	PlayerCharacter(Texture*charachterTexture, Vector2f position, Texture* suitTexture, Texture*weaponTexture, float maxSpeed, float healthPoints, float defencePoints, float damagePoints, float attackRange);
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
	Vector2f suitOffset;
	Vector2f weaponOffset;

	//inputs
	Keyboard::Key kbUp = Keyboard::Key::W;
	Keyboard::Key kbDown = Keyboard::Key::S;
	Keyboard::Key kbLeft = Keyboard::Key::A;
	Keyboard::Key kbRight = Keyboard::Key::D;
	Keyboard::Key kbInteract = Keyboard::Key::E;
	Mouse::Button mbShoot = Mouse::Button::Left;

	void Move();
	void GetHit(float damagePoints);
};

