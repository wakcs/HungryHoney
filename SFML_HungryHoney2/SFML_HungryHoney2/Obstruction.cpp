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
	float playerSpeed = player->GetMaxSpeed();
	if (rectObstruction.contains(playerPos))
	{
		//top or bottom collision
		if (playerPos.y > rectObstruction.top && fabs((rectObstruction.top + rectObstruction.height) - playerPos.y) <= playerSpeed) {
			player->blockTop = true;
		}
		else if (playerPos.y < rectObstruction.top + rectObstruction.height && fabs(rectObstruction.top - playerPos.y) <= playerSpeed) {
			player->blockBottom = true;
		}
		//left or right collision
		if (playerPos.x > rectObstruction.left && fabs((rectObstruction.left+rectObstruction.width)-playerPos.x) <= playerSpeed) {
			player->blockLeft = true;
		}
		else if (playerPos.x < rectObstruction.left + rectObstruction.width && fabs(rectObstruction.left - playerPos.x) <= playerSpeed) {
			player->blockRight = true;
		}
	}
}

void Obstruction::Draw(RenderWindow & window)
{
	window.draw(sprtObstruction);
}
