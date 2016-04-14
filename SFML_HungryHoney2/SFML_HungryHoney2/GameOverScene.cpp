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
	if (!Scene::Initialize() || !txtrBackground.loadFromFile(dirLevel+"go_screen.png")) {
		return false;
	}
	sprtBackground.setTexture(txtrBackground);
	sprtBackground.setPosition(TransformableExtender::SetCenter(&sprtBackground, windowSize->x / 2, windowSize->y / 2));
	
	btnRetry = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f((windowSize->x / 2) - 150, windowSize->y - 100), "Retry");
	btnExit= MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f((windowSize->x / 2) + 150, windowSize->y - 100), "Exit To Menu");

	txtGameOverDesc.setFont(gameFont);
	txtEndScore.setFont(gameFont);
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
	btnRetry.Draw(window);
	btnExit.Draw(window);
	Scene::Draw(window);
	window.display();
}

void GameOverScene::SetGameOver(GameOverState gameoverState, float endScore)
{
	switch (gameoverState)
	{
	case GameOverScene::NOTIME:
		txtGameOverDesc.setString("You have survived the bees and  \ngathered plenty honey for breakfast.");
		break;
	case GameOverScene::DEATH:
		txtGameOverDesc.setString("You have been overrun by bees.");
		break;
	}
	txtGameOverDesc.setPosition(TransformableExtender::SetCenter(&txtGameOverDesc, Vector2f(windowSize->x / 2, windowSize->y / 2)));
	oldScore = ScoreManager::ReadScore();
	newScore = endScore;
	if (newScore > oldScore) {
		txtEndScore.setString("[NEW] Final Score: " + to_string(int(endScore)));
	}
	else {
		txtEndScore.setString("Final Score: " + to_string(int(endScore)));
	}
	txtEndScore.setPosition(TransformableExtender::SetCenter(&txtEndScore, Vector2f(windowSize->x / 2, windowSize->y / 2 + txtGameOverDesc.getLocalBounds().height+txtEndScore.getLocalBounds().height)));
}

void GameOverScene::SaveScore()
{
	if (newScore >= 0 && newScore > oldScore && !bScoreSaved) {
		ScoreManager::WriteScore(newScore);
		bScoreSaved = true;
	}
}
