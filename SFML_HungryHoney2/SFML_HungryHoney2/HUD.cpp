#include "stdafx.h"
#include "HUD.h"


HUD::HUD()
{
}

HUD::HUD(PlayerCharacter * player, View * mainView, float timeInSeconds, Texture* healthTexture, Texture* shieldTexture, Font* hudFont)
{
	HUD::player = player;
	HUD::mainView = mainView;
	gameDuration = Time(seconds(timeInSeconds));
	sprtHealth.setTexture(*healthTexture);
	sprtShield.setTexture(*shieldTexture);
	txtHealth.setFont(*hudFont);
	txtShield.setFont(*hudFont);
	txtScore.setFont(*hudFont);
	txtTime.setFont(*hudFont);
	healthOffset = Vector2f(-(mainView->getSize().x / 2), -(mainView->getSize().y / 2));
	healthTxtOffset = Vector2f(healthOffset.x + sprtHealth.getLocalBounds().width, healthOffset.y);
	shieldOffset = Vector2f(healthOffset.x + 100, healthOffset.y);
	shieldTxtOffset = Vector2f(shieldOffset.x + sprtShield.getLocalBounds().width, shieldOffset.y);
	timeOffset = Vector2f((mainView->getSize().x / 2) - 250, -(mainView->getSize().y / 2));
	scoreOffset = Vector2f(-100, (mainView->getSize().y / 2) - 50);
}


HUD::~HUD()
{
}

void HUD::Update()
{
	Vector2f viewPos = mainView->getCenter();

	txtHealth.setString(to_string(int(player->GetHealthPoints())));
	txtHealth.setPosition(viewPos + healthTxtOffset);
	sprtHealth.setPosition(viewPos + healthOffset);

	txtShield.setString(to_string(int(player->GetDefencePoints())));
	txtShield.setPosition(viewPos + shieldTxtOffset);
	sprtShield.setPosition(viewPos + shieldOffset);

	int timeLeft = -(gameElapse.getElapsedTime().asSeconds() - gameDuration.asSeconds());
	txtTime.setString("Time Left: " + to_string(timeLeft));
	txtTime.setPosition(viewPos + timeOffset);

	txtScore.setString("Score: " + to_string(int(player->GetScore())));
	txtScore.setPosition(viewPos + scoreOffset);

}

void HUD::Draw(RenderWindow & window)
{
	window.draw(sprtHealth);
	window.draw(sprtShield);
	window.draw(txtHealth);
	window.draw(txtShield);
	window.draw(txtTime);
	window.draw(txtScore);
}
