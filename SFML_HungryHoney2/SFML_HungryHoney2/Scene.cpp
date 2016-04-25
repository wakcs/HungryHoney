#include "stdafx.h"
#include "Scene.h"


Scene::Scene()
{
}

Scene::Scene(GameState * state, Vector2i * windowSize)
{
	Scene::state = state;
	Scene::windowSize = windowSize;
	char path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, path);
	dirSprite.insert(0, path);
	dirLevel.insert(0, path);
	dirFont.insert(0, path);
	dirAudio.insert(0, path);
}


Scene::~Scene()
{
}

bool Scene::Initialize()
{
	if (!txtrBtnClicked.loadFromFile(dirSprite + "btnClick.png") || !txtrBtnUnclicked.loadFromFile(dirSprite + "btnUnclick.png") ||
		!txtrMouse.loadFromFile(dirSprite + "mouse.png") || !gameFont.loadFromFile(dirFont + "kenpixel_square.ttf") || !bufClick.loadFromFile(dirAudio+"click.ogg"))
	{
		return false;
	}
	sprtMouse.setTexture(txtrMouse);
	return true;
}

void Scene::Update(RenderWindow & window)
{
	sprtMouse.setPosition(window.mapPixelToCoords(Mouse::getPosition(window)));
}

void Scene::Draw(RenderWindow & window)
{
	window.draw(sprtMouse);
}
