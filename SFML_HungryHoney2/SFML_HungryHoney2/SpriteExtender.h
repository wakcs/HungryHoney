#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class SpriteExtender
{
public:
	SpriteExtender();
	~SpriteExtender();

	static Vector2f GetCenter(Sprite * sprite);
	static void SetCenter(Sprite * sprite, Vector2f position);
	static void SetCenter(Sprite * sprite, float x, float y);
};

