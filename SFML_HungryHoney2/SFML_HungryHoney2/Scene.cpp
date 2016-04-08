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
	return false;
}

void Scene::Update()
{
}

void Scene::Draw(RenderWindow & window)
{
}
