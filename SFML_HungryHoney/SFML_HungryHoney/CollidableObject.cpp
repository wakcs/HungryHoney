#include "stdafx.h"
#include "CollidableObject.h"

CollidableObject::CollidableObject()
{
}

CollidableObject::CollidableObject(Texture& texture, Vector2f position, float scale)
	: GameObject(texture, position, scale)
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

void CollidableObject::CollisionDetect(CollidableObject* object)
{
	if (objCollider.intersects(object->objCollider))
	{
		Vector2f direction = Vector2Extender::NormalizeVector(objPosition, object->objPosition);
		objVelocity = Vector2f(-(direction.x*objVelocity.x), -(direction.y*objVelocity.y));
	}
}
