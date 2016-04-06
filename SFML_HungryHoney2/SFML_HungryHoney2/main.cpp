// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <SFML\Graphics.hpp>

int main()
{
	//Uncomment if you want to hide the console window
	//FreeConsole();

	//creates the window where te magic happens
	sf::RenderWindow window(sf::VideoMode(200, 200), "Hungry Honey - By Geert Cocu");
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		window.display();
	}
    return 0;
}

