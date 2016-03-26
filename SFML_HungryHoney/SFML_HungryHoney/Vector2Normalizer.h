#pragma once
#include <SFML\System.hpp>
using namespace sf;
class Vector2Normalizer
{
public:
	Vector2Normalizer();
	~Vector2Normalizer();

	static float NormalizeFloat(Vector2f source, Vector2f target);
	static Vector2f NormalizeVector(Vector2f source, Vector2f target);
};

