#include "Human.h"



Human::Human(int health, bool isSick, const Position& position, int rand)
	: Person(position, rand)
{
	this->health = health;
	this->isSick = isSick;
	if (isSick)
	{
		color = sf::Color::Red;
	}
	else
	{
		color = sf::Color::White;
	}
}

void Human::update(sf::Color color)
{
	if (color == sf::Color::Red && !isSick)
	{
		isSick = true;
		this->color = sf::Color::Red;
	}
	else if (isSick && color == sf::Color::White)
	{
		isSick = false;
		this->color = sf::Color::White;
	}

	if (isSick)
	{
		health--;
	}
	if (health <= 0)
	{
		if (isAlive)
		{
			isAlive = false;
			this->color = sf::Color::Green;
		}
	}
}


sf::Color Human::move(sf::Color color, Position direction)
{
	if (isAlive)
	{
		if (isSick)
			return sf::Color::Red;
		else
			return sf::Color::White;
	}
}
