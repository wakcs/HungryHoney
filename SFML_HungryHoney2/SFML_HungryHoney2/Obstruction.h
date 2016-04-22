#pragma once
#include "PlayerCharacter.h"

class Obstruction
{
public:
	Obstruction();
	Obstruction(Texture * txtrObstruction, Vector2f position, PlayerCharacter * player);
	~Obstruction();

	void Update();
	void Draw(RenderWindow& window);

private:
	Sprite sprtObstruction;
	FloatRect rectObstruction;
	PlayerCharacter * player;
};

