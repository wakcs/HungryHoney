#pragma once
#include "CollidableObject.h"
#include "PlayerObject.h"

class InteractableObject :
	public CollidableObject
{
public:
	float interactRange;
	Vector2i spawnArea;
	Sprite objInteract;

	InteractableObject();
	InteractableObject(Texture& texture, Vector2f position, float scale, Texture& interact, Vector2i spawnArea, float interactRange);
	~InteractableObject();

	void UpdateObject(PlayerObject* player);
	void DrawObject(RenderWindow &window);

protected:
	Vector2u interactDimensions;
	bool inRange;
};

