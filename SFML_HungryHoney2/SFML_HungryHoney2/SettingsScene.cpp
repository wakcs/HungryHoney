#include "stdafx.h"
#include "SettingsScene.h"


SettingsScene::SettingsScene()
{
}

SettingsScene::SettingsScene(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
}


SettingsScene::~SettingsScene()
{
}

bool SettingsScene::Initialize()
{
	if (!Scene::Initialize() || !txtrHtp.loadFromFile(dirLevel + "howtoplay_screen.png")){
	return false;
	}
	sprtHtp.setTexture(txtrHtp);
	sprtHtp.setPosition(TransformableExtender::SetCenter(&sprtHtp, Vector2f(sprtHtp.getLocalBounds().width/2, windowSize->y / 2)));

	txtScoreText.setFont(gameFont);
	txtScoreText.setString("High Score:");
	txtScoreText.setPosition(TransformableExtender::SetCenter(&txtScoreText, Vector2f(windowSize->x - 200, windowSize->y / 2 - 150)));

	txtScoreNum.setFont(gameFont);
	txtScoreNum.setString(to_string(ScoreManager::ReadScore()));
	txtScoreNum.setPosition(TransformableExtender::SetCenter(&txtScoreNum, Vector2f(windowSize->x - 200, windowSize->y / 2-100)));

	btnReset = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(windowSize->x - 200, windowSize->y / 2), "Reset");
	btnBack = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(windowSize->x - 200, windowSize->y - 100), "Back");
	return true;
}

void SettingsScene::Update(RenderWindow & window)
{
	Scene::Update(window);
	if (btnReset.isClicked(window)) {
		ScoreManager::WriteScore(0);
		txtScoreNum.setString(to_string(ScoreManager::ReadScore()));
	}
	if (btnBack.isClicked(window)) {
		*state = MAINMENU;
	}
}

void SettingsScene::Draw(RenderWindow & window)
{
	window.clear();
	window.draw(sprtHtp);
	window.draw(txtScoreText);
	window.draw(txtScoreNum);
	btnReset.Draw(window);
	btnBack.Draw(window);
	Scene::Draw(window);
	window.display();
}
