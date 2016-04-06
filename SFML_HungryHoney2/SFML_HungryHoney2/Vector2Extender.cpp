#include "stdafx.h"
#include "Vector2Extender.h"


Vector2Extender::Vector2Extender()
{
}


Vector2Extender::~Vector2Extender()
{
}

float Vector2Extender::NormalizeFloat(Vector2f source, Vector2f target)
{
	Vector2f vDistance(source - target);
	float distance = sqrt((vDistance.x*vDistance.x) + (vDistance.y*vDistance.y));
	return distance;
}

Vector2f Vector2Extender::NormalizeVector(Vector2f source, Vector2f target)
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

Vector2f Vector2Extender::RandomVectorCoords(Vector2i bounds, bool center)
{
	const int delay = 2;
	int rnd;
	Clock clock;
	Time waittime = Time(milliseconds(delay));
	bool changeX = false;
	int rndX = 0, rndY = 0;

	while (rndX == 0 || rndY == 0)
	{
		if (clock.getElapsedTime().asMilliseconds() > waittime.asMilliseconds()) {
			rnd = rand();
			if (changeX) 
			{
				rndX = (rnd % bounds.x);
				if (center) {
					rndX = rndX - (bounds.x / 2);
				}
			}
			else 
			{
				rndY = (rnd % bounds.y);
				if (center) {
					rndY = rndY - (bounds.y / 2);
				}
			}
			changeX = !changeX;
			clock.restart();
		}
	}
	return Vector2f(rndX, rndY);
}

