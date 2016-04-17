#pragma once
#include <SFML\Graphics.hpp>
#include "PlayerCharacter.h"
class HUD
{
public:
	HUD();
	HUD(PlayerCharacter * player, View * mainView, Texture* healthTexture, Texture* shieldTexture, Font* hudFont);
	~HUD();

	void Update();
	void Draw(RenderWindow & window);

private:
	PlayerCharacter * player;
	View * mainView;
	Sprite sprtHealth, sprtShield;
	Text txtHealth, txtShield, txtScore;
	Vector2f healthOffset, healthTxtOffset, shieldOffset, shieldTxtOffset, scoreOffset;
	int timeLeft;
};

