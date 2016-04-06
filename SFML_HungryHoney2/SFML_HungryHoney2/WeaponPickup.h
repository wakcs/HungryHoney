#pragma once
#include "Pickup.h"
class WeaponPickup :
	public Pickup
{
public:
	WeaponPickup();
	WeaponPickup(Texture* itemTexture, Texture* InteractTexture, Vector2f position, int pickupRange, int damagePoints, int attackRange);
	~WeaponPickup();

	void Update(PlayerCharacter* player);
	void Draw(RenderWindow&window);

private:
	bool bPickedUp;
	int damagePoints, attackRange;
};

