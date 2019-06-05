#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "MapInterpreter.h"
#include "PopulationCreator.h"
#include "Person.h"
#pragma once



class MapDrawer : public MapInterpreter
{
private:
	std::vector<std::unique_ptr<Person>> people;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Event event;
	void updatePeople();
	void updateTexture();
	void drawImage();
	void movePerson(Position, Position, sf::Color);
public:
	MapDrawer(const std::string&, int, int, int, int, int);
};

