#pragma once
#include "Character.h"
#include "PlayerCharacter.h"

class BeeCharacter :
	public Character
{
public:
	BeeCharacter();
	BeeCharacter(Texture* charachterTexture, Vector2f position);
	~BeeCharacter();

	//called in the update
	void Update(PlayerCharacter * player);

private:
	float fPursuitRange, fAngle = 1;
	Vector2f circlePos, center;

	void Move(PlayerCharacter * player);
};

