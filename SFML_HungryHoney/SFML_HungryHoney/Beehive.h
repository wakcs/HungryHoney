#pragma once
#include "InteractableObject.h"
class Beehive :
	public InteractableObject
{
public:
	float interactRange;
	Vector2i spawnArea;
	Sprite objInteract;

	Beehive();
	Beehive(Texture& texture, Vector2f position, float scale, Texture& interact, Vector2i spawnArea, float interactRange);
	~Beehive();

	void UpdateObject(PlayerObject* player);
};

