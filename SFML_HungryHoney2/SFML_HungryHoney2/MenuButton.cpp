#include "stdafx.h"
#include "MenuButton.h"


MenuButton::MenuButton()
{
}

MenuButton::MenuButton(Texture * unclickedTexture, Texture * clickedTexture, Font * textFont, SoundBuffer*bufClick, Vector2f position, string buttonText)
{
	sprtBtnUnClicked.setTexture(*unclickedTexture);
	sprtBtnClicked.setTexture(*clickedTexture);
	txtButton.setFont(*textFont);
	txtButton.setString(buttonText);
	sndClick.setBuffer(*bufClick);
	SetPosition(position);
}


MenuButton::~MenuButton()
{
}

bool MenuButton::isClicked(RenderWindow & window)
{
	Vector2f mousePos(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
	if (Mouse::isButtonPressed(Mouse::Left) && rectButton.contains(mousePos)) {
		sndClick.play();
		isPressed = true;
	}
	else {
		isPressed = false;
	}
	return isPressed;
}

void MenuButton::Draw(RenderWindow & window)
{
	if (isPressed) {
		window.draw(sprtBtnClicked);
	}
	else {
		window.draw(sprtBtnUnClicked);
	}
	window.draw(txtButton);
}

void MenuButton::SetPosition(Vector2f position)
{
	sprtBtnUnClicked.setPosition(TransformableExtender::SetCenter(&sprtBtnUnClicked, position));
	sprtBtnClicked.setPosition(TransformableExtender::SetCenter(&sprtBtnClicked, position));
	txtButton.setPosition(TransformableExtender::SetCenter(&txtButton, position));
	rectButton = sprtBtnUnClicked.getGlobalBounds();
}

void MenuButton::SetScale(float scaleX, float scaleY)
{
	sprtBtnUnClicked.setScale(scaleX, scaleY);
	sprtBtnClicked.setScale(scaleX, scaleY);
	txtButton.setScale(scaleX, scaleY);
}
