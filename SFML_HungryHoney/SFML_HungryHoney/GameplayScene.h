#pragma once
#include "Scene.h"
class GameplayScene :
	public Scene
{
public:
	list<GameObject> backgroundList;
	const Vector2i mapSize = Vector2i(8000, 8000);
	const Vector2i blockSize = Vector2i(400, 400);
	const int scale = 25;
	const int rectSize = 16;
	Texture txtrGrass, txtrBody, txtrSuit, txtrWeapon, txtrBeehive, txtrInteract, txtrHealth, txtrSun;
	Image imgSheet, imgSun;
	Font hudFont;
	View mainView;
	const float viewScale = 5;
	PlayerObject player;
	BeeObject bee;
	Hud mainHud;
	Beehive hive1, hive2;

	GameplayScene();
	GameplayScene(Vector2f* windowSize, GameState* state);
	~GameplayScene();

	void Initialize();
	void Update();
	void Draw(RenderWindow &window);
};

