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
}


Scene::~Scene()
{
}

bool Scene::Initialize()
{
	if (!txtrBtnClicked.loadFromFile(dirSprite + "btnClick.png") || !txtrBtnUnclicked.loadFromFile(dirSprite + "btnUnclick.png") || 
		!txtrMouse.loadFromFile(dirSprite + "mouse.png") || !gameFont.loadFromFile(dirFont+"kenpixel_square.ttf"))
	{
		return false;
	}
	sprtMouse.setTexture(txtrMouse);
	return true;
}

void Scene::Update(RenderWindow & window)
{
	sprtMouse.setPosition(Vector2f(Mouse::getPosition(window).x, Mouse::getPosition(window).y));
}

void Scene::Draw(RenderWindow & window)
{
	window.draw(sprtMouse);
}
