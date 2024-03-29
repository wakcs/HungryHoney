#pragma once
#include "Scene.h"
#include "GameplayScene.h"

class MainMenuScene :
	public Scene
{
public:
	MainMenuScene();
	MainMenuScene(GameState * state, Vector2i * windowSize);
	~MainMenuScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window, GameplayScene*gameplay);
	virtual void Draw(RenderWindow & window);

private:
	Vector2f screenCenter;

	Texture txtrBackground;
	MenuButton btnPlay, btnSettings, btnAbout, btnExit;

	Text txtTitle;
	Sprite sprtBackground;
};

