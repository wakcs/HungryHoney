#include "stdafx.h"
#include "WeaponObject.h"


WeaponObject::WeaponObject()
{
}

WeaponObject::WeaponObject(Texture & texture, Vector2f position, float scale, Texture & interact, Vector2i spawnArea, float interactRange, float damagePoints, float damageRange)
	:InteractableObject(texture, position, scale, interact, spawnArea, interactRange)
{
	WeaponObject::damagePoints = damagePoints;
	WeaponObject::damageRange = damageRange;
}


WeaponObject::~WeaponObject()
{
}

void WeaponObject::UpdateObject(PlayerObject * player)
{
	InteractableObject::UpdateObject(player);
	if (inRange && Keyboard::isKeyPressed(player->kbInteract)) {
		player->weapon = objSprite;
		player->damagePoints = damagePoints;
		player->damageRange = damageRange;
		drawObject = false;
	}
}

void WeaponObject::DrawObject(RenderWindow & window)
{
	if (drawObject) {
		InteractableObject::DrawObject(window);
	}
}
