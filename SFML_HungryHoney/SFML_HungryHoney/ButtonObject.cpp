#include "stdafx.h"
#include "ButtonObject.h"


ButtonObject::ButtonObject()
{
}

ButtonObject::ButtonObject(Texture & texture, Vector2f position, float scale)
	: CollidableObject(texture, position, scale)
{
}


ButtonObject::~ButtonObject()
{
}

bool ButtonObject::CollisionDetect(Vector2i * mousePos)
{
	if (objCollider.contains(mousePos->x, mousePos->y)) {
		return true;
	}
	else {
		return false;
	}
}
