#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerObject.h"

using namespace sf;
using namespace std;
class Hud
{
public:
	View* mainView;
	PlayerObject* player;
	Sprite sprtHealthBar, sprtSunRising;
	Text txtScore, txtTime;
	Texture txtrSunRising;
	Vector2u v2uSunSize;
	Time gameDuration;
	Clock clock;
	Vector2f posHealthBar, posScore, posTime, posSun;
	float fSunStep; 
	int secondsLeft, tick;

	Hud();
	Hud(Texture& txtrHealthBar, Texture& txtrSun, Font& font, PlayerObject* player, Time gameDuration, View* mainView);
	~Hud();

	void UpdateHud();
	void DrawHud(RenderWindow& window);

private:
	float scale;
};

