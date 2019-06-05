	#include "RandomGenerator.h"
#include "Person.h"
#include <iostream>
#pragma once



class Human : public Person
{
private:

	int health;
	bool isSick;
public:
	Human(int, bool, const Position&, int);
	sf::Color move(sf::Color, Position);
	void update(sf::Color color);
};

