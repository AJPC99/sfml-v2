#include "RandomGenerator.h"
#include "Person.h"
#pragma once
#include <iostream>


class GraftingDoctor : public Person
{
private:
	RandomGenerator r;
	void moveCase(int, int);
public:
	GraftingDoctor(const Position&, int);
	void move();
};
