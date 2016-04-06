#pragma once
#include "InteractableObject.h"
class SuitObject :
	public InteractableObject
{
public:
	float defencePoints;
	SuitObject();
	SuitObject(Texture& texture, Vector2f position, float scale, Texture& interact, Vector2i spawnArea, float interactRange, float defencePoints);
	~SuitObject();

	void UpdateObject(PlayerObject* player);
	void DrawObject(RenderWindow &window);

private:
	bool drawObject;
};

