#pragma once
#include "CollidableObject.h"
class ButtonObject :
	public CollidableObject
{
public:
	ButtonObject();
	ButtonObject(Texture& texture, Vector2f position, float scale);
	~ButtonObject();

	bool CollisionDetect(Vector2i* mousePos);
};

