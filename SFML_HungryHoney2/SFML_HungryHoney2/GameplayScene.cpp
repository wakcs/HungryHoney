#include "stdafx.h"
#include "GameplayScene.h"


GameplayScene::GameplayScene()
{
}

GameplayScene::GameplayScene(GameState * state, Vector2i * windowSize)
	:Scene(state, windowSize)
{
}


GameplayScene::~GameplayScene()
{
}

bool GameplayScene::Initialize()
{
	mainView = View(Vector2f(windowSize->x / 2, windowSize->y / 2), Vector2f(windowSize->x, windowSize->y));
	mainView.zoom(0.5f);

	fieldBorder = FloatRect(-256, -520, 496, 1004);

	if (!txtrBackground.loadFromFile(dirLevel + "bee_field.png") || !txtrPlayer.loadFromFile(dirSprite + "playerBody.png") || !txtrHealth.loadFromFile(dirSprite + "health.png") ||
		!txtrShield.loadFromFile(dirSprite + "shield.png") || !txtrBee.loadFromFile(dirSprite + "bee.png") || !txtrBeeHealth.loadFromFile(dirSprite + "healthBee.png") ||
		!txtrInteract.loadFromFile(dirSprite + "interact.png") || !txtrHive.loadFromFile(dirSprite + "hive.png") || !txtrRobe.loadFromFile(dirSprite + "bathrobe.png") ||
		!txtrBeeSuit.loadFromFile(dirSprite + "beekeepsuit.png") || !txtrStick.loadFromFile(dirSprite + "stick.png") || !txtrSmoker.loadFromFile(dirSprite + "smoker.png")
		|| !txtrWallVer.loadFromFile(dirSprite + "fence_ver.png") || !txtrWallHor.loadFromFile(dirSprite + "fence_hor.png") || !txtrTree.loadFromFile(dirSprite + "tree.png") ||
		!bufPlayerHit.loadFromFile(dirAudio + "player_hit.ogg") || !bufBeeHit.loadFromFile(dirAudio + "bee_hit.ogg") || !bufBeeHive.loadFromFile(dirAudio + "score.ogg") ||
		!bufPickup.loadFromFile(dirAudio + "pickup.ogg") || !Scene::Initialize())
	{
		return false;
	}

	//background
	sprtBackground.setTexture(txtrBackground);
	sprtBackground.setPosition(TransformableExtender::SetCenter(&sprtBackground, 0, 0));

	//Player
	player = PlayerCharacter(&txtrPlayer, playerSpawn, &bufPlayerHit, NULL, NULL, plrSpeed, plrHP, plrDefP, plrDamP, plrAtRange);

	//HUD
	mainHud = HUD(&player, &mainView, &txtrHealth, &txtrShield, &gameFont);

	//Bees
	AddBee();

	//Pickups
	SetPickups();

	//obstructions
	wallLeft = Obstruction(&txtrWallVer, Vector2f(-264, 0), &player);
	obstructions.push_back(&wallLeft);
	wallRight = Obstruction(&txtrWallVer, Vector2f(264, 0), &player);
	obstructions.push_back(&wallRight);
	wallTop = Obstruction(&txtrWallHor, Vector2f(0, -520), &player);
	obstructions.push_back(&wallTop);
	wallBot = Obstruction(&txtrWallHor, Vector2f(0, 520), &player);
	obstructions.push_back(&wallBot);

	SetTrees();
	obstructions.push_back(&tree1);
	obstructions.push_back(&tree2);
	obstructions.push_back(&tree3);
	obstructions.push_back(&tree4);
	obstructions.push_back(&tree5);

	return true;
}

void GameplayScene::Update(RenderWindow & window, GameOverScene* gameOver)
{
	for each (Obstruction* obstruct in obstructions)
	{
		obstruct->Update();
	}
	for each (BeehivePickup* hive in hives)
	{
		hive->Update(&player);
	}
	for each (SuitPickup* suit in suits)
	{
		suit->Update(&player);
	}
	for each (WeaponPickup* weapon in weapons)
	{
		weapon->Update(&player);
	}
	for each (BeeCharacter* bee in bees)
	{
		bee->Update(&player);
	}
	if (beeTimer.getElapsedTime().asSeconds() > beeDelay.asSeconds()) {
		AddBee();
		beeTimer.restart();
	}
	player.Update(bees);
	mainView.setCenter(TransformableExtender::GetCenter(&player.sprtCharacter));
	mainHud.Update();
	if (player.IsDead()) {
		gameOver->SetGameOver(player.GetScore());
		Reset();
		*state = GAMEOVER;
	}
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		*state = MAINMENU;
	}
}

void GameplayScene::Draw(RenderWindow & window)
{
	window.clear();
	window.draw(sprtBackground);
	for each (Obstruction* obstruct in obstructions)
	{
		obstruct->Draw(window);
	}
	for each (BeehivePickup* hive in hives)
	{
		hive->Draw(window);
	}
	for each (SuitPickup* suit in suits)
	{
		suit->Draw(window);
	}
	for each (WeaponPickup* weapon in weapons)
	{
		weapon->Draw(window);
	}
	for each (BeeCharacter* bee in bees)
	{
		bee->Draw(window);
	}
	player.Draw(window);
	window.setView(mainView);
	mainHud.Draw(window);
	window.display();
}

void GameplayScene::AddBee()
{
	if (beeCount < 10) {
		switch (beeCount)
		{
		case 0:
			bee1 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee1);
			break;
		case 1:
			bee2 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee2);
			break;
		case 2:
			bee3 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee3);
			break;
		case 3:
			bee4 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee4);
			break;
		case 4:		
			bee5 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee5);
			break;
		case 5:		
			bee6 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee6);
			break;		
		case 6:
			bee7 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee7);
			break;
		case 7:
			bee8 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee8);
			break;
		case 8:
			bee9 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee9);
			break;
		case 9:
			bee10 = BeeCharacter(&txtrBee, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHit, beeSpeed, beeHP, beeDamP, beeAtRange, beePurRange, &txtrBeeHealth, fieldBorder);
			bees.push_back(&bee10);
			break;
		}
		beeCount++;
		cout << "Bee Count: " << beeCount << endl;
	}
}

void GameplayScene::SetPickups()
{	
	//Hives
	hives.clear();
	hive1 = BeehivePickup(&txtrHive, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHive, 32, fieldBorder);
	hives.push_back(&hive1);
	hive2 = BeehivePickup(&txtrHive, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHive, 32, fieldBorder);
	hives.push_back(&hive2);
	hive3 = BeehivePickup(&txtrHive, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHive, 32, fieldBorder);
	hives.push_back(&hive3);
	hive4 = BeehivePickup(&txtrHive, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHive, 32, fieldBorder);
	hives.push_back(&hive4);
	hive5 = BeehivePickup(&txtrHive, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufBeeHive, 32, fieldBorder);
	hives.push_back(&hive5);
	//suits
	suits.clear();
	robeSuit = SuitPickup(&txtrRobe, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufPickup, 20, 5);
	suits.push_back(&robeSuit);
	beeSuit = SuitPickup(&txtrBeeSuit, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufPickup, 20, 15);
	suits.push_back(&beeSuit);

	//weapons
	weapons.clear();
	stick = WeaponPickup(&txtrStick, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufPickup, 32, 10, 32);
	weapons.push_back(&stick);
	smoker = WeaponPickup(&txtrSmoker, &txtrInteract, Vector2Extender::RandomVectorCoords(fieldBorder), &bufPickup, 32, 20, 48);
	weapons.push_back(&smoker);
}

void GameplayScene::SetTrees()
{
	tree1 = Obstruction(&txtrTree, Vector2Extender::RandomVectorCoords(fieldBorder), &player);
	tree2 = Obstruction(&txtrTree, Vector2Extender::RandomVectorCoords(fieldBorder), &player);
	tree3 = Obstruction(&txtrTree, Vector2Extender::RandomVectorCoords(fieldBorder), &player);
	tree4 = Obstruction(&txtrTree, Vector2Extender::RandomVectorCoords(fieldBorder), &player);
	tree5 = Obstruction(&txtrTree, Vector2Extender::RandomVectorCoords(fieldBorder), &player);
}


void GameplayScene::Reset()
{
	//Player
	player = PlayerCharacter(&txtrPlayer, playerSpawn, &bufPlayerHit, NULL, NULL, plrSpeed, plrHP, plrDefP, plrDamP, plrAtRange);

	//Bees
	beeTimer.restart();
	bees.clear();
	beeCount = 0;
	AddBee();

	//Pickups
	SetPickups();

	//Trees
	SetTrees();
}
