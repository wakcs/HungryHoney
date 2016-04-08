#include "stdafx.h"
#include "SpriteExtender.h"


SpriteExtender::SpriteExtender()
{
}


SpriteExtender::~SpriteExtender()
{
}

Vector2f SpriteExtender::GetCenter(Sprite * sprite)
{
	Vector2f spritePos = sprite->getPosition();
	FloatRect spriteRect = sprite->getLocalBounds();
	return Vector2f(spritePos.x + (spriteRect.width / 2), spritePos.y + (spriteRect.height / 2));
}

Vector2f SpriteExtender::SetCenter(Sprite * sprite, Vector2f position)
{
	FloatRect spriteRect = sprite->getLocalBounds();
	return Vector2f(position.x - (spriteRect.width / 2), position.y - (spriteRect.height / 2));
}

Vector2f SpriteExtender::SetCenter(Sprite * sprite, float x, float y)
{
	FloatRect spriteRect = sprite->getLocalBounds();
	return Vector2f(x - (spriteRect.width / 2), y - (spriteRect.height / 2));
}

