#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerCharacter.h"
using namespace sf;
using namespace std;

class Pickup
{
public:
	Pickup();
	Pickup(Texture* itemTexture, Texture* InteractTexture, Vector2f position, int pickupRange);
	~Pickup();

	void Update(PlayerCharacter * player);
	void Draw(RenderWindow& window);

protected:
	Sprite sprtItem, sprtInteract;
	int iPickupRange;
	bool bInRange;

	void SetPosition(Vector2f position);
};

