#pragma once
#include "Scene.h"
#include "ScoreManager.h"
class GameOverScene :
	public Scene
{
public:
	enum GameOverState {
		NOTIME,
		DEATH
	};

	GameOverScene();
	GameOverScene(GameState * state, Vector2i * windowSize);
	~GameOverScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

	void SetGameOver(GameOverState gameoverState, float endScore);

private:
	float oldScore, newScore;
	bool bScoreSaved = false;

	Texture txtrBackground;
	Sprite sprtBackground;
	Text txtGameOverDesc, txtEndScore;
	MenuButton btnRetry, btnExit;

	void SaveScore();
};

