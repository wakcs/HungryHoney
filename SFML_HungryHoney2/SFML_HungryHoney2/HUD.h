#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerCharacter.h"
class HUD
{
public:
	HUD();
	HUD(PlayerCharacter * player, View * mainView, float timeInSeconds, Texture* healthTexture, Texture* shieldTexture, Font* hudFont);
	~HUD();

	void Update();
	void Draw(RenderWindow & window);

private:
	PlayerCharacter * player;
	View * mainView;
	Sprite sprtHealth, sprtShield;
	Text txtHealth, txtShield, txtTime, txtScore;
	Clock gameElapse;
	Time gameDuration;
	Vector2f healthOffset, healthTxtOffset, shieldOffset, shieldTxtOffset, timeOffset, scoreOffset;
};

