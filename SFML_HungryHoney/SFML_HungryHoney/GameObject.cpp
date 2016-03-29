#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(Texture& texture, Vector2f position, float scale)
{	
	objSprite.setTexture(texture);
	objSprite.setScale(scale, scale);
	spriteDimensions = texture.getSize();
	objPosition = position;
	objSprite.setPosition(objPosition);
}

GameObject::~GameObject()
{
}

void GameObject::UpdateObject()
{
	objSprite.move(objVelocity);
	objPosition = objSprite.getPosition();
}

void GameObject::DrawObject(RenderWindow &window)
{
	window.draw(objSprite);
}
