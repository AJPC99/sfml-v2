#include "MapDrawer.h"



MapDrawer::MapDrawer(const std::string& imageName, int turnDelay, int humanHealth, int numberOfHumans,
	int numberOfSickHumans, int numberOfDoctors) : MapInterpreter(imageName)
{
	PopulationCreator p(humanHealth, numberOfHumans, numberOfSickHumans, numberOfDoctors, 0, lands);
	people = p.moveVector();
	for (int i = 0; i < people.size(); ++i)
	{
		Position p = people[i]->getPosition();
		image->setPixel(p.x, p.y, people[i]->getColor());
	}

	window.create(sf::VideoMode(imageWidth, imageHeight), "Simulation");
	texture.loadFromImage(*image);
	sprite.setTexture(texture);
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Sleep(turnDelay);
		updatePeople();
		updateTexture();
		window.clear();
		drawImage();
		window.display();
	}
}
void MapDrawer::updatePeople()
{
	Position direction;
	for (int i = 0; i < people.size(); ++i)
	{
		Position position = people[i]->getPosition();
		switch (people[i]->getDirection())
		{
		case 0:
			direction = Position(1, 0);
			break;
		case 1:
			direction = Position(1, 1);
			break;
		case 2:
			direction = Position(1, -1);
			break;
		case 3:
			direction = Position(0, 1);
			break;
		case 4:
			direction = Position(0, -1);
			break;
		case 5:
			direction = Position(-1, 1);
			break;
		case 6:
			direction = Position(-1, 0);
			break;
		case 7:
			direction = Position(-1, -1);
			break;
		}
		sf::Color color;		
		people[i]->update(image->getPixel(position.x, position.y));
		if ((position.x + direction.x > 0 && position.x + direction.x < imageWidth)
			&& (position.y + direction.y > 0 && position.y + direction.y < imageHeight))
		{
			if (image->getPixel(position.x + direction.x, position.y + direction.y).g == 255)
			{
				Position newPosition(position.x + direction.x, position.y + direction.y);
				movePerson(position, newPosition, people[i]->getColor());
				people[i]->setPosition(newPosition);
			}
			else if(image->getPixel(position.x + direction.x, position.y + direction.y) == sf::Color::White)
			{
				std::cout << "XD";
				color = people[i]->move(image->getPixel(position.x + direction.x, position.y + direction.y), direction);
				image->setPixel(position.x + direction.x, position.y + direction.y, color);
			}
		}

	}
}
void MapDrawer::updateTexture()
{
	texture.loadFromImage(*image);
}

void MapDrawer::drawImage()
{
	window.draw(sprite);
}

void MapDrawer::movePerson(Position oldPosition, Position newPosition, sf::Color color)
{
	image->setPixel(oldPosition.x, oldPosition.y, sf::Color::Green);
	image->setPixel(newPosition.x, newPosition.y, color);
}