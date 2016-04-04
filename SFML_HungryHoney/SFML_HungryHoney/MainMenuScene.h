#pragma once
#include "Scene.h"
class MainMenuScene :
	public Scene
{
public:
	MainMenuScene();
	MainMenuScene(Vector2f* windowSize, GameState* state);
	~MainMenuScene();

	void Initialize();
	void Update();
	void Draw(RenderWindow &window);
};

