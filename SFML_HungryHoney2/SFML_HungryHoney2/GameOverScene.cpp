#include "stdafx.h"
#include "GameOverScene.h"


GameOverScene::GameOverScene()
{
}

GameOverScene::GameOverScene(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
}


GameOverScene::~GameOverScene()
{
}

bool GameOverScene::Initialize()
{
	if (!Scene::Initialize() || !txtrBackground.loadFromFile(dirLevel + "go_screen.png")) {
		return false;
	}
	sprtBackground.setTexture(txtrBackground);
	sprtBackground.setPosition(TransformableExtender::SetCenter(&sprtBackground, windowSize->x / 2, windowSize->y / 2));
	
	btnRetry = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, &bufClick, Vector2f((windowSize->x / 2) - 150, windowSize->y - 100), "Retry");
	btnExit = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, &bufClick, Vector2f((windowSize->x / 2) + 150, windowSize->y - 100), "Exit To Menu");

	txtGameOverDesc.setFont(gameFont);
	txtGameOverDesc.setString("You have been overrun by bees.");
	txtEndScore.setFont(gameFont);
	txtNewHigh.setFont(gameFont);
	txtNewHigh.setColor(Color::Red);
	txtNewHigh.setString("New Highscore!");
	return true;
}

void GameOverScene::Update(RenderWindow & window)
{
	Scene::Update(window);
	SaveScore();
	if (btnRetry.isClicked(window)) {
		*state = GAMEPLAY;
	}
	if (btnExit.isClicked(window)) {
		*state = MAINMENU;
	}
}

void GameOverScene::Draw(RenderWindow & window)
{
	window.clear();
	window.setView(window.getDefaultView());
	window.draw(sprtBackground);
	window.draw(txtGameOverDesc);
	window.draw(txtEndScore);
	if (newScore > oldScore) {
		window.draw(txtNewHigh);
	}
	btnRetry.Draw(window);
	btnExit.Draw(window);
	Scene::Draw(window);
	window.display();
}

void GameOverScene::SetGameOver(float endScore)
{
	txtGameOverDesc.setPosition(TransformableExtender::SetCenter(&txtGameOverDesc, Vector2f(windowSize->x / 2, windowSize->y / 2)));
	oldScore = ScoreManager::ReadScore();
	newScore = endScore;
	txtEndScore.setString("Final Score: " + to_string(int(endScore)));
	txtEndScore.setPosition(TransformableExtender::SetCenter(&txtEndScore, Vector2f(windowSize->x / 2, txtGameOverDesc.getPosition().y + txtGameOverDesc.getLocalBounds().height + txtEndScore.getLocalBounds().height)));
	txtNewHigh.setPosition(TransformableExtender::SetCenter(&txtNewHigh, Vector2f(windowSize->x / 2, txtEndScore.getPosition().y + txtEndScore.getLocalBounds().height + txtNewHigh.getLocalBounds().height)));
}

void GameOverScene::SaveScore()
{
	if (newScore >= 0 && newScore > oldScore && !bScoreSaved) {
		ScoreManager::WriteScore(newScore);
		bScoreSaved = true;
	}
}
