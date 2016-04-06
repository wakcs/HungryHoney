#include "stdafx.h"
#include "Beehive.h"

Beehive::Beehive()
{
}

Beehive::Beehive(Texture & texture, Vector2f position, float scale, Texture & interact, Vector2i spawnArea, float interactRange)
	: InteractableObject(texture, position, scale, interact, spawnArea, interactRange)
{
	objInteract.setTexture(interact);
	interactDimensions = interact.getSize();
	objInteract.setPosition((objPosition.x + spriteDimensions.x / 2) - interactDimensions.x / 2, objPosition.y - interactDimensions.y);
	Beehive::spawnArea = spawnArea;
	Beehive::interactRange = spriteDimensions.x + interactRange;
}

Beehive::~Beehive()
{
}

void Beehive::UpdateObject(PlayerObject* player)
{
	InteractableObject::UpdateObject(player);
	if (inRange && Keyboard::isKeyPressed(player->kbInteract)) {
		player->score += 100;
		cout << "Interacted, moving..." << endl;
		objSprite.setPosition(Vector2Extender::RandomVectorCoords(spawnArea, true));
	}
	objInteract.setPosition((objPosition.x + spriteDimensions.x / 2), objPosition.y - interactDimensions.y);
}
