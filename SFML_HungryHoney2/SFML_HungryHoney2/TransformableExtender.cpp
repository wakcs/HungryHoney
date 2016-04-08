#include "stdafx.h"
#include "TransformableExtender.h"

Vector2f TransformableExtender::GetCenter(Sprite * sprite)
{
	Vector2f pos = sprite->getPosition();
	FloatRect rect = sprite->getLocalBounds();
	return Vector2f(pos.x + (rect.width / 2), pos.y + (rect.height / 2));
}
Vector2f TransformableExtender::GetCenter(Shape * shape)
{
	Vector2f pos = shape->getPosition();
	FloatRect rect = shape->getLocalBounds();
	return Vector2f(pos.x + (rect.width / 2), pos.y + (rect.height / 2));
}
Vector2f TransformableExtender::GetCenter(Text * text)
{
	Vector2f pos = text->getPosition();
	FloatRect rect = text->getLocalBounds();
	return Vector2f(pos.x + (rect.width / 2), pos.y + (rect.height / 2));
}

Vector2f TransformableExtender::SetCenter(Sprite * sprite, Vector2f position)
{
	FloatRect rect = sprite->getLocalBounds();
	return Vector2f(position.x - (rect.width / 2), position.y - (rect.height / 2));
}
Vector2f TransformableExtender::SetCenter(Shape * shape, Vector2f position)
{
	FloatRect rect = shape->getLocalBounds();
	return Vector2f(position.x - (rect.width / 2), position.y - (rect.height / 2));
}
Vector2f TransformableExtender::SetCenter(Text * text, Vector2f position)
{
	FloatRect rect = text->getLocalBounds();
	return Vector2f(position.x - (rect.width / 2), position.y - (rect.height / 2));
}

Vector2f TransformableExtender::SetCenter(Sprite * sprite, float x, float y)
{
	FloatRect rect = sprite->getLocalBounds();
	return Vector2f(x - (rect.width / 2), y - (rect.height / 2));
}
Vector2f TransformableExtender::SetCenter(Shape * shape, float x, float y)
{
	FloatRect rect = shape->getLocalBounds();
	return Vector2f(x - (rect.width / 2), y - (rect.height / 2));
}
Vector2f TransformableExtender::SetCenter(Text * text, float x, float y)
{
	FloatRect rect = text->getLocalBounds();
	return Vector2f(x - (rect.width / 2), y - (rect.height / 2));
}

