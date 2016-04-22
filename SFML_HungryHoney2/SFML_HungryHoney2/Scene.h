#pragma once
#include <Windows.h>
#include <iostream>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Vector2Extender.h"
#include "TransformableExtender.h"
#include "MenuButton.h"

using namespace sf;
using namespace std;

class Scene
{
public:
	enum GameState {
		MAINMENU,
		SETTINGS,
		ABOUT,
		GAMEPLAY,
		GAMEOVER
	};

	Scene();
	Scene(GameState * state, Vector2i * windowSize);
	~Scene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

protected:
	GameState * state;
	Vector2i * windowSize;
	string dirSprite = "\\Resources\\Sprites\\", dirLevel = "\\Resources\\Backgrounds\\", dirFont = "\\Resources\\Fonts\\", dirAudio = "\\Resources\\Audio\\";

	Texture txtrMouse, txtrBtnClicked, txtrBtnUnclicked;
	Font gameFont;
	Sprite sprtMouse;

};

