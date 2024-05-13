#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Id
{
private:
	std::string title;
	int age;
	std::string occupation;
	sf::Sprite picture;

public:
	Id(const std::string title, int age, const std::string occupation, const sf::Sprite picture);
	void Draw(sf::RenderWindow window);
};
