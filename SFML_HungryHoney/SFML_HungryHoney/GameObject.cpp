#include "stdafx.h"
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

GameObject::GameObject(Texture& texture, Vector2f position)
{	
	objSprite.setTexture(texture);
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
