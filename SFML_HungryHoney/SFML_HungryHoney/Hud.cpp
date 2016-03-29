#include "stdafx.h"
#include "Hud.h"


Hud::Hud(Texture & txtrHealthBar, Image& imgSunRising, Font& font, PlayerObject& player, Time gameDuration, Vector2f& screenSize)
	: player(player), screenSize(screenSize)
{
	sprtHealthBar.setTexture(txtrHealthBar);
	sprtHealthBar.setScale(player.healthPoints*hpBarMultiplier, 10);
	//sprtHealthBar.setPosition(0, screenSize.y - 10);

	v2uSunSize = imgSunRising.getSize();
	txtrSunRising.loadFromImage(imgSunRising, IntRect(0, 0, v2uSunSize.x, v2uSunSize.y / 2));
	sprtSunRising.setTexture(txtrSunRising);
	//sprtSunRising.setPosition(screenSize.x - v2uSunSize.x, 0);

	//txtScore.setFont(font);
	txtScore.setColor(Color::White);
	//txtScore.setPosition(0, 0);
	//txtTime.setFont(font);
	txtTime.setColor(Color::White);
	//txtTime.setPosition(screenSize.x - v2uSunSize.x - 100, 0);

	Hud::gameDuration = gameDuration;
}

Hud::~Hud()
{
}

void Hud::UpdateHud(View& mainCam)
{
	sprtHealthBar.setScale(player.healthPoints*hpBarMultiplier, 10);
	sprtHealthBar.setPosition(mainCam.getCenter() + posHealthBar);
	txtScore.setString("Score: " + player.score);
	float secondsLeft = clock.getElapsedTime().asSeconds() - gameDuration.asSeconds();
	txtTime.setString("Time Left: " + to_string(secondsLeft));
}

void Hud::DrawHud(RenderWindow & window)
{
	window.draw(sprtHealthBar);
	window.draw(sprtSunRising);
	window.draw(txtScore);
	window.draw(txtTime);
}
