#include "stdafx.h"
#include "Obstruction.h"


Obstruction::Obstruction()
{
}

Obstruction::Obstruction(Texture * txtrObstruction, Vector2f position, PlayerCharacter * player)
{
	sprtObstruction.setTexture(*txtrObstruction);
	sprtObstruction.setOrigin(sprtObstruction.getLocalBounds().width / 2, sprtObstruction.getLocalBounds().height / 2);
	sprtObstruction.setPosition(position);
	rectObstruction = sprtObstruction.getGlobalBounds();
	Obstruction::player = player;
}


Obstruction::~Obstruction()
{
}

void Obstruction::Update()
{
	Vector2f playerPos = player->sprtCharacter.getPosition();
	if (rectObstruction.contains(playerPos))
	{
		//top or bottom collision
		if (playerPos.y > rectObstruction.top) {
			player->blockTop = true;
		}
		else if (playerPos.y < rectObstruction.top + rectObstruction.height) {
			player->blockBottom = true;
		}

		//left or right collision
		if (playerPos.x > rectObstruction.left) {
			player->blockLeft = true;
		}
		else if (playerPos.x < rectObstruction.left + rectObstruction.width) {
			player->blockRight = true;
		}
	}
}

void Obstruction::Draw(RenderWindow & window)
{
	window.draw(sprtObstruction);
}
