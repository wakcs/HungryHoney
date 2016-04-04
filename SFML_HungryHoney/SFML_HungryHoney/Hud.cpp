#include "stdafx.h"
#include "Hud.h"

Hud::Hud()
{
	posHealthBar = Vector2f(-10, -10);
	posScore = Vector2f(0, -10);
	posTime = Vector2f(10, -10);
	scale = 10;
}

Hud::Hud(Texture & txtrHealthBar, Texture & txtrSun, Font& font, PlayerObject* player, Time gameDuration, View* mainView)
{
	scale = 5;
	Hud::player = player;
	Hud::mainView = mainView;

	posHealthBar = Vector2f(-(mainView->getSize().x/2), -(mainView->getSize().y / 2));
	sprtHealthBar.setTexture(txtrHealthBar);

	v2uSunSize = txtrSun.getSize();
	sprtSunRising.setTexture(txtrSun);

	txtScore.setFont(font);
	txtScore.setColor(Color::White);
	txtScore.setScale(scale, scale);
	posScore = Vector2f(-(mainView->getSize().x / 2), (mainView->getSize().y / 2) - scale *50);

	txtTime.setFont(font);
	txtTime.setColor(Color::White);
	txtTime.setScale(scale, scale);
	posTime = Vector2f((mainView->getSize().x / 2) - scale * 275, (mainView->getSize().y / 2) - scale * 45);
	posSun = Vector2f(posTime.x - v2uSunSize.x, posTime.y);
	fSunStep = (v2uSunSize.y / 2) / gameDuration.asSeconds();

	Hud::gameDuration = gameDuration;
}

Hud::~Hud()
{
}

void Hud::UpdateHud()
{
	sprtHealthBar.setScale(player->healthPoints*scale*2, scale*2);
	sprtHealthBar.setPosition(mainView->getCenter() + posHealthBar);

	txtScore.setString("Score: " + to_string(player->score));
	txtScore.setPosition(mainView->getCenter() + posScore);
		
	if (secondsLeft < 0) {
		secondsLeft = clock.getElapsedTime().asSeconds() - gameDuration.asSeconds();
		if (tick < secondsLeft) {
			posSun.y -= fSunStep;
		}
		tick = secondsLeft;
	}
		txtTime.setString("Time Left: " + to_string(abs(secondsLeft)));
		txtTime.setPosition(mainView->getCenter() + posTime);

		sprtSunRising.setPosition(mainView->getCenter() + posSun);
}

void Hud::DrawHud(RenderWindow & window)
{
	window.draw(sprtHealthBar);
	window.draw(sprtSunRising);
	window.draw(txtScore);
	window.draw(txtTime);
}
