#include "stdafx.h"
#include "GameplayScene.h"


GameplayScene::GameplayScene() : Scene()
{
}
GameplayScene::GameplayScene(Vector2f* windowSize, GameState* state) : Scene(windowSize, state)
{
}
GameplayScene::~GameplayScene()
{
}

void GameplayScene::Initialize()
{	
	//2D Camera
	mainView = View(FloatRect(Vector2f(0, 0), *windowSize));
	mainView.zoom(viewScale);
	//BACKGROUND, WILL CHANGE TO TMXPARSER
	txtrGrass.loadFromFile(dirSprite + "grass.png");
	for (int x = -(mapSize.x / 2) - blockSize.x; x < (mapSize.x / 2) + blockSize.x; x += blockSize.x)
	{
		for (int y = -(mapSize.y / 2) - blockSize.y; y < (mapSize.y / 2) + blockSize.y; y += blockSize.y)
		{
			GameObject background(txtrGrass, Vector2f(x, y), scale);
			backgroundList.push_back(background);
		}
	}
	//player
	if (txtrBody.loadFromFile(dirSprite + "playerBody.png")) {
		player = PlayerObject(txtrBody, Vector2f(0, 0), 25, txtrSuit, txtrWeapon, 10, 0, 0, 50, &mainView);
	}
	//suits
	if (txtrSuit.loadFromFile(dirSprite + "bathrobe.png")) {
		suitBathrobe = SuitObject(txtrSuit, Vector2Extender::RandomVectorCoords(Vector2i(2000, 2000), true), 25, txtrInteract, mapSize, 200, 1);
	}
	if (txtrSuit.loadFromFile(dirSprite + "beekeeper.png")) {
		suitBeekeeper = SuitObject(txtrSuit, Vector2Extender::RandomVectorCoords(Vector2i(2000, 2000), true), 25, txtrInteract, mapSize, 200, 1);
	}
	//weapons
	if (txtrWeapon.loadFromFile(dirSprite + "smoker.png")) {
		weapSmoker = WeaponObject(txtrWeapon, Vector2Extender::RandomVectorCoords(Vector2i(2000, 2000), true), 25, txtrInteract, mapSize, 200, 10, 500);
	}
	//bees
	bee = BeeObject(txtrBody, Vector2f(800, 800), 0.5f, 2, 0, 2, 400, &player, 1000);
	//beehives
	txtrBeehive.loadFromFile(dirSprite + "chest.png");
	txtrInteract.loadFromFile(dirSprite + "letter_E.png");
	hive1 = Beehive(txtrBeehive, Vector2Extender::RandomVectorCoords(Vector2i(2000, 2000), true), 25, txtrInteract, mapSize, 400);
	hive2 = Beehive(txtrBeehive, Vector2Extender::RandomVectorCoords(Vector2i(2000, 2000), true), 25, txtrInteract, mapSize, 400);

	//HUD
	txtrHealth.loadFromFile(dirSprite + "HealthBar.png");
	hudFont.loadFromFile(dirFont + "kenpixel_square.ttf");
	txtrSun.loadFromFile(dirSprite + "sunny.png");
	mainHud = Hud(txtrHealth, txtrSun, hudFont, &player, Time(seconds(60)), &mainView);
}

void GameplayScene::Update()
{
	player.UpdateObject();
	player.CollisionDetect(&hive1);
	player.CollisionDetect(&hive2);
	bee.UpdateObject();
	suitBathrobe.UpdateObject(&player);
	suitBeekeeper.UpdateObject(&player);
	weapSmoker.UpdateObject(&player);
	hive1.UpdateObject(&player);
	hive2.UpdateObject(&player);

	if (Mouse::isButtonPressed(player.mbShoot)) {
		//player.Attack(nearest bee)
	}
	mainHud.UpdateHud();
	if (mainHud.secondsLeft == 0 || player.healthPoints<=0) {
		*state = CREDITS;
	}
}

void GameplayScene::Draw(RenderWindow & window)
{
	window.clear();
	for each (GameObject background in backgroundList)
	{
		background.DrawObject(window);
	}
	hive1.DrawObject(window);
	hive2.DrawObject(window);
	suitBathrobe.DrawObject(window);
	suitBeekeeper.DrawObject(window);
	player.DrawObject(window);
	bee.DrawObject(window);
	window.setView(mainView);
	mainHud.DrawHud(window);
	window.display();
}
