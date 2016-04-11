#pragma once
#include "Scene.h"
class AboutScene :
	public Scene
{
public:
	AboutScene();
	AboutScene(GameState * state, Vector2i * windowSize);
	~AboutScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

private:
	Texture txtrAbout;
	Sprite sprtAbout;
	MenuButton btnBack;
};

