#include "Snake.h"

using namespace std;
using namespace sf;

Snake::Snake(RenderWindow &window, int size, int speed) : m_window(window), m_size(size), m_speed(speed)
{
	this->m_timeToUpdate = 250;
	this->m_currentTime = 0.0f;
	this->m_left = m_up = m_down = false;
	this->m_right = true;
	srand(std::time(0));
	this->addCase();
	this->addCase();

	this->m_food.setRadius(m_size / 2);
	this->m_food.setFillColor(sf::Color::Red);
	this->foodGenerator();
}

/*
 * Generate food position to be draw 
 */
void Snake::foodGenerator()
{
	int randomX = rand() % (m_window.getSize().x / this->m_size);
	int randomY = rand() % (m_window.getSize().y / this->m_size);

	
	for (unsigned int i = 0; i < m_snake.size(); i++)
	{
		if ((this->m_snake[0].getPosition().x != randomX * this->m_size) && (this->m_snake[0].getPosition().y != randomY))
		{
			this->m_food.setPosition(randomX * m_size, randomY * m_size);
		}
	}
}

void Snake::addCase()
{
	sf::RectangleShape rect;
	rect.setSize(sf::Vector2f(32, 32));
	rect.setOutlineColor(sf::Color::Black);
	rect.setOutlineThickness(1.0f);

	if (this->m_snake.empty())
	{
		rect.setFillColor(sf::Color::Red);
		rect.setPosition(320, 256);
	}
	else
	{
		rect.setFillColor(sf::Color::Yellow);
		rect.setPosition(this->m_snake[this->m_snake.size() - 1].getPosition().x - rect.getSize().x, this->m_snake[this->m_snake.size() - 1].getPosition().y);
	}
	this->m_snake.push_back(rect);
}

/*
 * Move the snake every 2.5sec and check collision
 */
void Snake::move()
{
	if (this->m_currentTime < this->m_timeToUpdate)
	{
		this->m_currentTime += this->m_clock.restart().asMilliseconds();
	}
	else
	{
		this->m_currentTime = 0.0f;

		if (this->m_snake.size() > 1)
		{
			for (unsigned int i = this->m_snake.size() - 1; i > 0; i--)
			{
				this->m_snake[i].setPosition(sf::Vector2f(this->m_snake[i - 1].getPosition().x, this->m_snake[i - 1].getPosition().y));
			}
		}
		int value = 1;
		-value;
		if (this->m_left)
			this->m_snake[0].move(-m_speed, 0);
		if (this->m_right)
			this->m_snake[0].move(m_speed, 0);
		if (this->m_up)
			this->m_snake[0].move(0, -m_speed);
		if (this->m_down)
			this->m_snake[0].move(0, m_speed);

		this->checkCollision();
	}
} 

void Snake::checkCollision()
{
	for (unsigned int i = 2; i < this->m_snake.size(); i++)
	{
		if (this->m_snake[0].getPosition().x == this->m_snake[i].getPosition().x && this->m_snake[0].getPosition().y == this->m_snake[i].getPosition().y)
		{
			this->m_window.close();
		}
	}

	// window borders collision
	if (this->m_snake[0].getPosition().x < 0 ||
		this->m_snake[0].getPosition().y < 0 ||
		this->m_snake[0].getPosition().x + this->m_snake[0].getSize().x > this->m_window.getSize().x ||
		this->m_snake[0].getPosition().y + this->m_snake[0].getSize().y > this->m_window.getSize().y)
	{
		m_window.close();
	}

	if (this->m_snake[0].getPosition().x == this->m_food.getPosition().x && this->m_snake[0].getPosition().y == this->m_food.getPosition().y)
	{
		this->addCase();
		this->foodGenerator();
	}
}

void Snake::update(Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
			case sf::Keyboard::Left:
				if (this->m_snake[0].getPosition().x - this->m_snake[0].getSize().x != this->m_snake[1].getPosition().x)
				{
					if (!this->m_left && !this->m_right)
					{

					}
				}
				break;
			case sf::Keyboard::Right:
				break;
			case sf::Keyboard::Up:
				break;
			case sf::Keyboard::Down:
				break;
			default:
				break;
		}
	}
}

void Snake::draw()
{
	this->m_window.draw(this->m_food);

	for (unsigned int i = 0; i < this->m_snake.size(); i++)
	{
		this->m_window.draw(this->m_snake[i]);
	}
}
