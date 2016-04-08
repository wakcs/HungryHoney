#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class SpriteExtender
{
public:
	SpriteExtender();
	~SpriteExtender();

	static Vector2f GetCenter(Sprite * sprite);
	static Vector2f SetCenter(Sprite * sprite, Vector2f position);
	static Vector2f SetCenter(Sprite * sprite, float x, float y);
};

