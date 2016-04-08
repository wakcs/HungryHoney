#pragma once
#include <Windows.h>
#include <iostream>
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Vector2Extender.h"
#include "TransformableExtender.h"

using namespace sf;
using namespace std;

class Scene
{
public:
	enum GameState {
		MAINMENU,
		CONTROLS,
		CREDITS,
		GAMEPLAY,
		GAMEOVER
	};

	Scene();
	Scene(GameState * state, Vector2i * windowSize);
	~Scene();

	virtual bool Initialize();
	virtual void Update();
	virtual void Draw(RenderWindow & window);

protected:
	GameState * state;
	Vector2i * windowSize;
	string dirSprite = "\\Resources\\Sprites\\", dirLevel = "\\Resources\\Levels\\", dirFont = "\\Resources\\Fonts\\";

};

