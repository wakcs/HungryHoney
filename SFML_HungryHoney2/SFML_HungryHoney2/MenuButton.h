#pragma once
#include <SFML\Graphics.hpp>
#include "TransformableExtender.h"

using namespace sf;
using namespace std;

class MenuButton
{
public:
	MenuButton();
	MenuButton(Texture*unclickedTexture, Texture*clickedTexture, Font*textFont, Vector2f position, string buttonText);
	~MenuButton();

	bool isClicked(RenderWindow & window);
	void Draw(RenderWindow & window);

private:
	Sprite sprtBtnUnClicked, sprtBtnClicked;
	Text txtButton;
	FloatRect rectButton;
	bool isPressed;

	Mouse::Button mbClick = Mouse::Button::Left;
};

