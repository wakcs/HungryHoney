#include "stdafx.h"
#include "BackgroundMusic.h"


BackgroundMusic::BackgroundMusic()
{
}

BackgroundMusic::BackgroundMusic(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
}


BackgroundMusic::~BackgroundMusic()
{
}

bool BackgroundMusic::Initialize()
{
	if (!Scene::Initialize() || !musicMain.openFromFile(dirAudio + "copycat.ogg") || !musicGameOver.openFromFile(dirAudio + "sadness.ogg")) {
		return false;
	}
	musicMain.setLoop(true);
	musicMain.setVolume(musicVol);
	musicGameOver.setVolume(musicVol);
	return true;
}

void BackgroundMusic::Update()
{
	if (*state != GameState::GAMEOVER && musicMain.getStatus() != Music::Playing)
	{
		musicGameOver.stop();
		musicMain.play();
	}
	if (*state == GameState::GAMEOVER && musicGameOver.getStatus() != Music::Playing) {
		musicMain.stop();
		musicGameOver.play();
	}
}
