#pragma once
#include "Scene.h"
class MessageBoxScene :
	public Scene
{
public:
	MessageBoxScene();
	MessageBoxScene(GameState * state, Vector2i * windowSize, string message);
	~MessageBoxScene();

	virtual bool Initialize();
	virtual void Update(RenderWindow & window);
	virtual void Draw(RenderWindow & window);

	MenuButton btnYes, btnNo;

private:
	Texture txtrWindow;
	Sprite sprtWindow;
	string message;
	Text txtMessage;
};

