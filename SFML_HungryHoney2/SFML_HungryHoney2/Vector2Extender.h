#pragma once
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
using namespace sf;
class Vector2Extender
{
public:
	Vector2Extender();
	~Vector2Extender();

	static float NormalizeFloat(Vector2f source, Vector2f target);
	static Vector2f NormalizeVector(Vector2f source, Vector2f target);
	static Vector2f RandomVectorCoords(Vector2i bounds, bool center);
	static Vector2f RandomVectorCoords(FloatRect bounds);
};

