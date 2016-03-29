#include "stdafx.h"
#include "CollidableObject.h"


CollidableObject::CollidableObject(Texture& texture, Vector2f position, float scale) : GameObject(texture, position, scale)
{
	objCollider = objSprite.getGlobalBounds();
}


CollidableObject::~CollidableObject()
{
}

void CollidableObject::UpdateObject()
{
	oldPosition = objPosition;
	GameObject::UpdateObject();
	objCollider = objSprite.getGlobalBounds();
}

void CollidableObject::DrawObject(RenderWindow & window)
{
	GameObject::DrawObject(window);
}

void CollidableObject::CollisionDetect(CollidableObject* object)
{
	if (objCollider.intersects(object->objCollider)) 
	{
		//cout << "Collision detected!" << endl;
		objVelocity = Vector2f(0, 0);
		objPosition = oldPosition;
		objSprite.setPosition(oldPosition);
	}
}
