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
		/*if (fabs(objVelocity.x) > 0) {
			objVelocity.x = 0;
			objPosition = Vector2f(oldPosition.x, objPosition.y);
			objSprite.setPosition(objPosition);
		}
		if (fabs(objVelocity.y) > 0) {
			objVelocity.y = 0;
			objPosition = Vector2f(objPosition.x, oldPosition.y);
			objSprite.setPosition(objPosition);
		}
		if (fabs(objVelocity.x) > 0 && fabs(objVelocity.y) > 0) {
			objVelocity = Vector2f(0, 0);
			objPosition = oldPosition;
			objSprite.setPosition(objPosition);
		}*/
	}
}
