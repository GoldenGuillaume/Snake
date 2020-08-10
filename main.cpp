#include "main.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main() {
	int difficulty = 0;

	cout << "==============" << "  SNAKE " << "==============" << endl << endl;
	cout << "Choose the difficulty level:" << endl << "1. Easy" << endl << "2. Medium" << endl << "3. Hard" << endl;
	
	do {
		cin >> difficulty;
		if (difficulty <= 0 && difficulty > 3)
			cout << endl << "The difficulty level selected isn't correct" << endl;
	} while (difficulty <= 0 && difficulty > 3);
	
	
	int windowSize = difficulty * 200;
	sf::RenderWindow window(sf::VideoMode(windowSize, windowSize), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
