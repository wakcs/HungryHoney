#include "stdafx.h"
#include "Vector2Normalizer.h"


Vector2Normalizer::Vector2Normalizer()
{
}


Vector2Normalizer::~Vector2Normalizer()
{
}

float Vector2Normalizer::NormalizeFloat(Vector2f source, Vector2f target)
{
	Vector2f vDistance(source - target);
	float distance = sqrt((vDistance.x*vDistance.x) + (vDistance.y*vDistance.y));
	return distance;
}

Vector2f Vector2Normalizer::NormalizeVector(Vector2f source, Vector2f target)
{
	Vector2f vDistance(source - target);
	float distance = sqrt((vDistance.x*vDistance.x) + (vDistance.y*vDistance.y));
	if (distance != 0) {
		return Vector2f(vDistance.x / distance, vDistance.y / distance);
	}
	else {
		return vDistance;
	}
}

