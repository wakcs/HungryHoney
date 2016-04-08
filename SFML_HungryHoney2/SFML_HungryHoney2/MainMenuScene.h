#pragma once
#include "Scene.h"
class MainMenuScene :
	public Scene
{
public:
	MainMenuScene();
	MainMenuScene(GameState * state, Vector2i * windowSize);
	~MainMenuScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

private:
	Vector2f screenCenter;

	Texture txtrBackground;
	MenuButton btnPlay, btnSettings, btnAbout, btnExit;

	Text txtTitle;
	Sprite sprtBackground;
};

