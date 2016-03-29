#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerObject.h"

using namespace sf;
using namespace std;
class Hud
{
public:
	Vector2f& screenSize;
	PlayerObject& player;
	Sprite sprtHealthBar, sprtSunRising;
	Text txtScore, txtTime;
	Texture txtrSunRising;
	Vector2u v2uSunSize;
	Time gameDuration;
	Clock clock;
	const Vector2f posHealthBar = Vector2f(-2000, -1500);

	Hud(Texture& txtrHealthBar, Image& imgSunRising, Font& font, PlayerObject& player, Time gameDuration, Vector2f& screenSize);
	~Hud();

	void UpdateHud(View& mainCam);
	void DrawHud(RenderWindow& window);

private:
	const float hpBarMultiplier = 10;
};

