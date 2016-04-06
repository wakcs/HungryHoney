#pragma once
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>

using namespace sf;
using namespace std;

class Scene
{
public:
	enum GameState {
		MAINMENU,
		INTRO,
		GAMEPLAY,
		PAUSE,
		CREDITS
	};

	GameState* state;
	Vector2f* windowSize;

	Scene();
	Scene(Vector2f* windowSize, GameState* state);
	~Scene();

	void Initialize();
	void Update();
	void Draw(RenderWindow &window);
};

