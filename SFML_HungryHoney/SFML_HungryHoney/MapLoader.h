#pragma once
#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
#include <cctype>
#include <fstream>
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

class MapLoader
{
public:
	MapLoader();
	MapLoader(string filePath, int tileSize);
	~MapLoader();

	void DrawMap(RenderWindow&window);
private:
	int tileSize;
	Texture tileTexture;
	Sprite tiles;
	Vector2i map[100][100]; 
	Vector2i loadCounter;
};

