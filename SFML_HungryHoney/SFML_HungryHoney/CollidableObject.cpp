#include "stdafx.h"
#include "CollidableObject.h"


CollidableObject::CollidableObject(Texture& texture, Vector2f position) : GameObject(texture, position)
{
	objCollider = objSprite.getGlobalBounds();
}


CollidableObject::~CollidableObject()
{
}

void CollidableObject::UpdateObject()
{
	GameObject::UpdateObject();
	objCollider = objSprite.getGlobalBounds();
}

void CollidableObject::DrawObject(RenderWindow & window)
{
	GameObject::DrawObject(window);
}

void CollidableObject::CollisionDetect(CollidableObject object)
{
	if (objCollider.intersects(object.objCollider)) 
	{
		cout << "Collision detected!" << endl;
		Vector2f offset(objPosition - object.objPosition);
		float length = sqrt((offset.x*offset.x) + (offset.y*offset.y));
		if (length != 0)
			objVelocity = Vector2f(offset.x / length, offset.y / length);
		else
			objVelocity = offset;
		cout << "Offset X:" << offset.x << " Y:" << offset.y << endl;
	}
}
