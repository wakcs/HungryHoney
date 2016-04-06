#include "stdafx.h"
#include "SuitObject.h"


SuitObject::SuitObject()
{
}

SuitObject::SuitObject(Texture & texture, Vector2f position, float scale, Texture & interact, Vector2i spawnArea, float interactRange, float defencePoints)
	: InteractableObject(texture,position,scale,interact,spawnArea,interactRange)
{
	SuitObject::defencePoints = defencePoints;
}


SuitObject::~SuitObject()
{
}

void SuitObject::UpdateObject(PlayerObject * player)
{
	InteractableObject::UpdateObject(player);
	if (inRange && Keyboard::isKeyPressed(player->kbInteract)) {
		player->suit = objSprite;
		player->defencePoints = defencePoints;
		drawObject = false;
	}
}

void SuitObject::DrawObject(RenderWindow & window)
{
	if (drawObject) {
		InteractableObject::DrawObject(window);
	}
}
