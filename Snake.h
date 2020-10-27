#ifndef CORE_SNAKE_H
#define CORE_SNAKE_H

#include <SFML/Graphics.hpp>

class Snake
{
	public:
		Snake(sf::RenderWindow &window, int size, int speed);

		void move();
		void update(sf::Event& event);
		void draw();

	private:
		sf::RenderWindow& m_window;
		sf::Clock m_clock;
		sf::CircleShape m_food;
		int m_timeToUpdate, m_size, m_speed;
		bool m_left, m_right, m_up, m_down;
		float m_currentTime;
		std::vector<sf::RectangleShape> m_snake;

		void checkCollision();
		void addCase();
		void foodGenerator();
};
#endif

