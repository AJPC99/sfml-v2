#include "Person.h"



Person::Person(const Position& position, int rand) : r(7, rand)
{
	isAlive = true;
	this->position = position;
}

Position Person::getPosition()
{
	return position;
}

int Person::getDirection()
{
	return r.random();
}

sf::Color Person::getColor()
{
	return color;
}
void Person::setPosition(Position newPosition)
{
	position = newPosition;
}