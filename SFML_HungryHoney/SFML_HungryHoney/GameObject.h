#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Vector2Extender.h"

using namespace sf;
using namespace std;

class GameObject
{
public:
	Sprite objSprite;
	Vector2f objPosition;
	Vector2f objVelocity;

	GameObject(Texture& texture, Vector2f position, float scale);
	~GameObject();

	void UpdateObject();
	void DrawObject(RenderWindow &window);

protected:
	Vector2u spriteDimensions;
};

