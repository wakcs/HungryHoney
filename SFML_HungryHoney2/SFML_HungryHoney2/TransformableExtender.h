#pragma once
#include <SFML\Graphics.hpp>
using namespace sf;
class TransformableExtender
{
public:
	static Vector2f GetCenter(Sprite * sprite);
	static Vector2f GetCenter(Shape * shape);
	static Vector2f GetCenter(Text * text);

	static Vector2f SetCenter(Sprite * sprite, Vector2f position);	
	static Vector2f SetCenter(Shape * shape, Vector2f position);	
	static Vector2f SetCenter(Text * text, Vector2f position);

	static Vector2f SetCenter(Sprite * sprite, float x, float y);
	static Vector2f SetCenter(Shape * shape, float x, float y);
	static Vector2f SetCenter(Text * text, float x, float y);
};

