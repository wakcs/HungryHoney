#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class GameObject
{
public:
	Sprite objSprite;
	Vector2f objPosition;
	Vector2f objVelocity;

	GameObject(Texture& texture, Vector2f position);
	~GameObject();

	void UpdateObject();
	void DrawObject(RenderWindow &window);
};

