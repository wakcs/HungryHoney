#pragma once
#include "GameObject.h"
class CollidableObject :
	public GameObject
{
public:
	FloatRect objCollider;

	CollidableObject(Texture& texture, Vector2f position);
	~CollidableObject();	

	void UpdateObject();
	void DrawObject(RenderWindow &window);
	void CollisionDetect(CollidableObject object);
};

