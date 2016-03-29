#include "stdafx.h"
#include "Beehive.h"

Beehive::Beehive(Texture & texture, Vector2f position, float scale, Texture & interact, Vector2i spawnArea, float interactRange, PlayerObject& player) : CollidableObject(texture, position, scale), player(player)
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

void Beehive::UpdateObject()
{
	float distance = Vector2Extender::NormalizeFloat(objPosition, player.objPosition);
	if (distance < interactRange) {
		inRange = true;
	}
	else {
		inRange = false;
	}
	if (inRange && Keyboard::isKeyPressed(player.kbInteract)) {
		player.score+=100;
		cout << "Interacted, moving..." << endl;
		objSprite.setPosition(Vector2Extender::RandomVectorCoords(spawnArea, true));
		cout << "New Coords: " << rndX << "," << rndY << endl;
	}
	objInteract.setPosition((objPosition.x + spriteDimensions.x / 2), objPosition.y - interactDimensions.y);
	CollidableObject::UpdateObject();
}

void Beehive::DrawObject(RenderWindow & window)
{
	CollidableObject::DrawObject(window);
	if (inRange) {
		window.draw(objInteract);
	}
}
