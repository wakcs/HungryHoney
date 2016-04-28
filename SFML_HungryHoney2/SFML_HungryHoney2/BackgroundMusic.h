#pragma once
#include "Scene.h"
class BackgroundMusic :
	public Scene
{
public:
	BackgroundMusic();
	BackgroundMusic(GameState * state, Vector2i * windowSize);
	~BackgroundMusic();

	virtual bool Initialize();
	void Update();

private:
	Music musicMain, musicGameOver;
	float musicVol = 25;
};

