#pragma once
#include "Character.h"

class PlayerCharacter :
	public Character
{
public:
	PlayerCharacter();
	PlayerCharacter(Texture*charachterTexture, Vector2f position, Texture* suitTexture, Texture*weaponTexture, int maxSpeed, int healthPoints, int defencePoints, int damagePoints, int attackRange);
	~PlayerCharacter();

	//called in the update
	void Update(vector<Character> *enemys);
	void Draw(RenderWindow&window);

	//getters
	int GetDefencePoints();
	int GetScore();
	Keyboard::Key GetInteractKey();

	//setters
	void SetDefencePoints(int defencePoints);
	void SetSuit(Sprite suit);
	void SetWeapon(Sprite weapon);
	void SetScore(int score);
	void AddScore(int points);
	void SubtractScore(int points);
	
private:
	int iDefencePoints, iScore;
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
	void GetHit(int damagePoints);
};

