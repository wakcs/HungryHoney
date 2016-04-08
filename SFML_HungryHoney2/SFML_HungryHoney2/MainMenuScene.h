#pragma once
#include "Scene.h"
#include "MenuButton.h"
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
	MenuButton btnTest;
	Texture txtrBtnClicked, txtrBtnUnclicked;
	Font btnFont;

};

