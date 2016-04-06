#pragma once
#include "Scene.h"
#include <list>
#include "GameObject.h"
#include "CollidableObject.h"
#include "PlayerObject.h"
#include "BeeObject.h"
#include "Beehive.h"
#include "Hud.h"
#include "SuitObject.h"
#include "WeaponObject.h"

class GameplayScene :
	public Scene
{
public:
	const string dirSprite = "Resources/Sprites/", dirAudio = "Resources/Audio/", dirFont = "Resources/Fonts/", dirLvl = "Resources/Levels/";
	list<GameObject> backgroundList;
	const Vector2i mapSize = Vector2i(8000, 8000);
	const Vector2i blockSize = Vector2i(400, 400);
	const int scale = 25, rectSize = 16;
	Texture txtrGrass, txtrBody, txtrSuit, txtrWeapon, txtrBeehive, txtrInteract, txtrHealth, txtrSun;
	Image imgSheet, imgSun;
	Font hudFont;
	View mainView;
	const float viewScale = 5;
	PlayerObject player;
	WeaponObject weapSmoker;
	SuitObject suitBathrobe, suitBeekeeper;
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

