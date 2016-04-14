#include "stdafx.h"
#include "MessageBoxScene.h"


MessageBoxScene::MessageBoxScene()
{
}

MessageBoxScene::MessageBoxScene(GameState * state, Vector2i * windowSize, string message)
	:Scene(state, windowSize)
{
	MessageBoxScene::message = message;
}


MessageBoxScene::~MessageBoxScene()
{
}

bool MessageBoxScene::Initialize()
{
	if (!Scene::Initialize() || !txtrWindow.loadFromFile(dirSprite + "message_window.png")) {
		return false;
	}
	Vector2f screenCenter = Vector2f(windowSize->x / 2, windowSize->y / 2);
	sprtWindow.setTexture(txtrWindow);
	sprtWindow.setPosition(TransformableExtender::SetCenter(&sprtWindow, screenCenter));
	txtMessage.setFont(gameFont);
	txtMessage.setString(message);
	txtMessage.setPosition(TransformableExtender::SetCenter(&txtMessage, screenCenter));
	btnYes = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(screenCenter.x - 100, screenCenter.y + 50), "Yes");
	btnNo = MenuButton(&txtrBtnUnclicked, &txtrBtnClicked, &gameFont, Vector2f(screenCenter.x + 100, screenCenter.y + 50), "No");
	return true;
}

void MessageBoxScene::Update(RenderWindow & window)
{
	Scene::Update(window);
}

void MessageBoxScene::Draw(RenderWindow & window)
{
	window.draw(sprtWindow);
	window.draw(txtMessage);
	btnYes.Draw(window);
	btnNo.Draw(window);
}
