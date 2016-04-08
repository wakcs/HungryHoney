#include "stdafx.h"
#include "MainMenuScene.h"


MainMenuScene::MainMenuScene()
{
}

MainMenuScene::MainMenuScene(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
}


MainMenuScene::~MainMenuScene()
{
}

bool MainMenuScene::Initialize()
{
	if (!txtrBtnClicked.loadFromFile(dirSprite + "btnClick.png") || !txtrBtnUnclicked.loadFromFile(dirSprite + "btnUnclick.png") || !btnFont.loadFromFile(dirFont + "kenpixel_square.ttf")) {
		return false;
	}
	btnTest = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &btnFont, Vector2f(windowSize->x / 2, windowSize->y / 2), "Click Me!");
}

void MainMenuScene::Update(RenderWindow & window)
{
	if (btnTest.isClicked(window)) {
		cout << "Test is Clicked!" << endl;
		*state = GAMEPLAY;
	}
}

void MainMenuScene::Draw(RenderWindow & window)
{
	window.clear();
	btnTest.Draw(window);
	window.display();
}
