#pragma once
#include "InteractableObject.h"
class WeaponObject :
	public InteractableObject
{
public:
	float damagePoints, damageRange;
	WeaponObject();
	WeaponObject(Texture& texture, Vector2f position, float scale, Texture& interact, Vector2i spawnArea, float interactRange, float damagePoints, float damageRange);
	~WeaponObject();

	void UpdateObject(PlayerObject* player);
	void DrawObject(RenderWindow &window);

private:
	bool drawObject;
};

