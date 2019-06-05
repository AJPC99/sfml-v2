#include <SFML/Graphics.hpp>
#include <memory>
#include "RandomGenerator.h"
#include "RandomGenerator.h"
#include "Position.h"
#pragma once



class Person
{
protected:
	bool isAlive;
	Position position;
	sf::Color color;
	RandomGenerator r;
	Person(const Position&, int);
public:
	sf::Color getColor();
	int getDirection();
	Position getPosition();
	void setPosition(Position);
	virtual sf::Color move(sf::Color, Position) = 0;
	virtual void update(sf::Color) = 0;
};
