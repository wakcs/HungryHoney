#include "stdafx.h"
#include "AboutScene.h"


AboutScene::AboutScene()
{
}

AboutScene::AboutScene(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
}


AboutScene::~AboutScene()
{
}

bool AboutScene::Initialize()
{
	if (!Scene::Initialize() || !txtrAbout.loadFromFile(dirLevel + "about_screen.png")) {
		return false;
	}
	sprtAbout.setTexture(txtrAbout);
	sprtAbout.setPosition(TransformableExtender::SetCenter(&sprtAbout, Vector2f(windowSize->x / 2, windowSize->y / 2)));
	btnBack = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, &bufClick, Vector2f(windowSize->x - 200, windowSize->y - 100), "Back");
	return true;
}

void AboutScene::Update(RenderWindow & window)
{
	Scene::Update(window);
	if (btnBack.isClicked(window)) {
		*state = MAINMENU;
	}
}

void AboutScene::Draw(RenderWindow & window)
{
	window.clear();
	window.draw(sprtAbout);
	btnBack.Draw(window);
	Scene::Draw(window);
	window.display();
}
