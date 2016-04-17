#pragma once
#include "Scene.h"
#include "ScoreManager.h"
class GameOverScene :
	public Scene
{
public:

	GameOverScene();
	GameOverScene(GameState * state, Vector2i * windowSize);
	~GameOverScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

	void SetGameOver(float endScore);

private:
	float oldScore, newScore;
	bool bScoreSaved = false;

	Texture txtrBackground;
	Sprite sprtBackground;
	Text txtGameOverDesc, txtEndScore, txtNewHigh;
	MenuButton btnRetry, btnExit;

	void SaveScore();
};

