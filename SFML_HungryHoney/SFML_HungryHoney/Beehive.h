#pragma once
#include "CollidableObject.h"
#include "PlayerObject.h"
class Beehive :
	public CollidableObject
{
public:
	float interactRange;
	Vector2i spawnArea;
	Sprite objInteract;
	PlayerObject& player;

	Beehive(Texture& texture, Vector2f position, float scale, Texture& interact, Vector2i spawnArea, float interactRange, PlayerObject& player);
	~Beehive();

	void UpdateObject();
	void DrawObject(RenderWindow &window);

protected:
	Vector2u interactDimensions;

private:
	bool inRange;
	int rnd = rand();
	Clock clock;
	Time waittime = Time(milliseconds(10));
	bool changeX;
	float rndX, rndY;
};

