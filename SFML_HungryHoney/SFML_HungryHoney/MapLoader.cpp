#include "stdafx.h"
#include "MapLoader.h"


MapLoader::MapLoader()
{
}

MapLoader::MapLoader(string filePath, int tileSize)
{
	MapLoader::tileSize = tileSize;
	loadCounter = Vector2i(0, 0);
	ifstream openfile(filePath);
	if (openfile.is_open())
	{
		string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);
		while (!openfile.eof())
		{
			string str;
			openfile >> str;
			char x = str[0], y = str[2];
			if (!isdigit(x) || !isdigit(y)) {
				map[loadCounter.x][loadCounter.y] = Vector2i(-1, -1);
			}
			else {
				map[loadCounter.x][loadCounter.y] = Vector2i(x - '0', y - '0');
			}
			if (openfile.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
			{
				loadCounter.x++;
			}
		}
		loadCounter.y++;
	}
}


MapLoader::~MapLoader()
{
}

void MapLoader::DrawMap(RenderWindow & window)
{
	for (int i = 0; i < loadCounter.x; i++)
	{
		for (int j = 0; j < loadCounter.y; j++)
		{
			if (map[i][j].x != -1 && map[i][j].y != -1) {
				tiles.setPosition(i * tileSize, j * tileSize);
				tiles.setTextureRect(IntRect(map[i][j].x*tileSize, map[i][j].y*tileSize, tileSize, tileSize));
				window.draw(tiles);
			}
		}
	}
}
