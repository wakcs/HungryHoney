#pragma once
#include "Scene.h"
#include "HUD.h"
#include "BeeCharacter.h"
#include "PlayerCharacter.h"
#include "BeehivePickup.h"
#include "SuitPickup.h"
#include "WeaponPickup.h"
#include "GameOverScene.h"

class GameplayScene :
	public Scene
{
public:
	GameplayScene();
	GameplayScene(GameState * state, Vector2i * windowSize);
	~GameplayScene();

	virtual bool Initialize();
	virtual void Update(GameOverScene * gameover);
	virtual void Draw(RenderWindow & window);

private:
	View mainView;

	Vector2f playerSpawn = Vector2f(0, -500);
	FloatRect fieldBorder;
	Texture txtrBackground;
	Sprite sprtBackground;
	Texture txtrBee, txtrBeeHealth, txtrPlayer, txtrHealth, txtrShield;
	Texture txtrInteract, txtrHive, txtrRobe, txtrBeeSuit, txtrStick, txtrSmoker;
	
	float plrSpeed = 2, plrHP = 100, plrDefP = 0, plrDamP = 5, plrAtRange = 16;
	float beeSpeed = 1, beeHP = 40, beeDamP = 20, beeAtRange = 32, beePurRange = 160;
	PlayerCharacter player;
	BeeCharacter bee1, bee2, bee3, bee4, bee5, bee6;
	vector<Character*> bees;

	HUD mainHud;

	SuitPickup robeSuit, beeSuit;
	vector<SuitPickup*> suits;
	WeaponPickup stick, smoker;
	vector<WeaponPickup*> weapons;
	BeehivePickup hive1, hive2, hive3;
	vector<BeehivePickup*> hives;

	Clock beeTimer;
	Time beeDelay = Time(seconds(2));
	int beeCount = 0;
	void AddBee();
	void SetPickups();
	void Reset();
};

