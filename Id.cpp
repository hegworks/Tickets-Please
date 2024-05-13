#include "Id.h"


Id::Id(const std::string title, int age, const std::string occupation, const sf::Sprite picture)
{
	this->age = age;
	this->title = title;
	this->occupation = occupation;
	this->picture = picture;
}

void Id::Draw(sf::RenderWindow window)
{
	//TODO
}
