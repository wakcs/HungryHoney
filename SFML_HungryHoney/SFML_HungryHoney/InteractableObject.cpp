#include "stdafx.h"
#include "InteractableObject.h"


InteractableObject::InteractableObject()
	:CollidableObject()
{
}

InteractableObject::InteractableObject(Texture & texture, Vector2f position, float scale, Texture & interact, Vector2i spawnArea, float interactRange)
	:CollidableObject(texture, position, scale)
{
	objInteract.setTexture(interact);
	interactDimensions = interact.getSize();
	objInteract.setPosition((objPosition.x + spriteDimensions.x / 2) - interactDimensions.x / 2, objPosition.y - interactDimensions.y);
	InteractableObject::spawnArea = spawnArea;
	InteractableObject::interactRange = spriteDimensions.x + interactRange;
}


InteractableObject::~InteractableObject()
{
}

void InteractableObject::UpdateObject(PlayerObject * player)
{
	CollidableObject::UpdateObject();
	float distance = Vector2Extender::NormalizeFloat(objPosition, player->objPosition);
	if (distance < interactRange) {
		inRange = true;
	}
	else {
		inRange = false;
	}
}

void InteractableObject::DrawObject(RenderWindow & window)
{
	CollidableObject::DrawObject(window);
	if (inRange) {
		window.draw(objInteract);
	}
}
