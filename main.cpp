#include "main.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Snake.h"

using namespace std;

int main() {
	int screenSize = 0;

	cout << "==============" << "  SNAKE " << "==============" << endl << endl;
	cout << "Choose the map size:" << endl << "1. Small" << endl << "2. Medium" << endl << "3. Large" << endl;
	
	do 
	{
		cin >> screenSize;
		if (screenSize <= 0 && screenSize > 3)
			cout << endl << "The selected size isn't correct" << endl;
	} while (screenSize <= 0 && screenSize > 3);
	
	int windowWidth, windowHeight;
	switch (screenSize)
	{
		case 1 :
			windowWidth = 400;
			windowHeight = 320;
			break;
		case 2:
			windowWidth = 800;
			windowHeight = 640;
			break;
		case 3:
			windowWidth = 1200;
			windowHeight = 860;
			break;
	}

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snake game by GoldenGuillaume");

	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	Snake snake(window, 32, 32);

	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
			snake.update(event);
		}
		window.clear(sf::Color::White);
		snake.draw();
		window.display();
	}

	return EXIT_SUCCESS;
}
