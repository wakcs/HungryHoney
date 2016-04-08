#include "stdafx.h"
#include "MainMenuScene.h"


MainMenuScene::MainMenuScene()
{
}

MainMenuScene::MainMenuScene(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
	screenCenter = Vector2f(windowSize->x / 2, windowSize->y / 2);
}


MainMenuScene::~MainMenuScene()
{
}

bool MainMenuScene::Initialize()
{
	
	if (!Scene::Initialize() || !txtrBackground.loadFromFile(dirLevel+"title_screen.png")) {
		return false;
	}
	btnPlay = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(screenCenter.x, screenCenter.y - 150),"Play Game");
	btnSettings = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(screenCenter.x, screenCenter.y - 50), "Settings");
	btnAbout = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(screenCenter.x, screenCenter.y + 50), "About");
	btnExit = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(screenCenter.x, screenCenter.y + 150), "Exit Game");
	sprtBackground.setTexture(txtrBackground);
	sprtBackground.setPosition(TransformableExtender::SetCenter(&sprtBackground, screenCenter));

	return true;
}

void MainMenuScene::Update(RenderWindow & window)
{
	Scene::Update(window);
	if (btnPlay.isClicked(window)) {
		*state = GAMEPLAY;
	}
	if (btnSettings.isClicked(window)) {
		//*state = SETTINGS;
	}	
	if (btnAbout.isClicked(window)) {
		//*state = ABOUT;
	}
	if (btnExit.isClicked(window)) {
		window.close();
	}
}

void MainMenuScene::Draw(RenderWindow & window)
{
	window.clear();
	window.setView(window.getDefaultView());
	window.draw(sprtBackground);
	btnPlay.Draw(window);
	btnSettings.Draw(window);
	btnAbout.Draw(window);
	btnExit.Draw(window);
	Scene::Draw(window);
	window.display();
}
