#pragma once
#include "GameObject.h"
class CollidableObject :
	public GameObject
{
public:
	FloatRect objCollider;
	Vector2f oldPosition;

	CollidableObject();
	CollidableObject(Texture& texture, Vector2f position, float scale);
	~CollidableObject();	

	void UpdateObject();
	void CollisionDetect(CollidableObject* object);
};

