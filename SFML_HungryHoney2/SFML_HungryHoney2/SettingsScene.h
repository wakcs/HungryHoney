#pragma once
#include "Scene.h"
#include "ScoreManager.h"
class SettingsScene :
	public Scene
{
public:
	SettingsScene();
	SettingsScene(GameState * state, Vector2i * windowSize);
	~SettingsScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

private:
	Texture txtrHtp;
	Sprite sprtHtp;

	Text txtScoreText, txtScoreNum;
	MenuButton btnReset, btnBack;
};

