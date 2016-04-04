#include "stdafx.h"
#include "Scene.h"

Scene::Scene()
{
	windowSize = new Vector2f(0, 0);
	state = new GameState(MAINMENU);
}

Scene::Scene(Vector2f* windowSize, GameState* state)
{
	Scene::windowSize = windowSize;
	Scene::state = state;
}

Scene::~Scene()
{
}

void Scene::Initialize()
{
}

void Scene::Update()
{
}

void Scene::Draw(RenderWindow & window)
{
	window.clear();
	window.display();
}
