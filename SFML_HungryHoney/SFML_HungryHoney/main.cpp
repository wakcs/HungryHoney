// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>
using namespace sf;

int main()
{
	//Uncomment if you want to hide the console window
	FreeConsole();

	//creates the window where te magic happens
	RenderWindow window(VideoMode(200, 200), "A SFML Project");
	CircleShape circle;

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
    return 0;
}

