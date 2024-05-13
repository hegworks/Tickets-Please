#include "Font.h"
#include "Id.h"
#include "Positions.h"
#include <iostream>

const std::string Id::backgroundTexturePath = "Assets/2D/IdCard.png";
sf::Texture Id::backgroundTexture;
sf::Sprite Id::backgroundSprite;

Id::Id(const std::string title, int age, const std::string occupation, const sf::Sprite picture)
{
	Font::SetStyle(this->title);
	this->title.setString(title);
	this->title.setPosition(Positions::IdTitle[0], Positions::IdTitle[1]);

	Font::SetStyle(this->age);
	this->age.setString(std::to_string(age));
	this->age.setPosition(Positions::IdAge[0], Positions::IdAge[1]);

	Font::SetStyle(this->occupation);
	this->occupation.setString(occupation);
	this->occupation.setPosition(Positions::IdOccupation[0], Positions::IdOccupation[1]);

	this->picture = picture;
	this->picture.setPosition(Positions::IdPicture[0], Positions::IdPicture[1]);
}


void Id::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(title);
	window.draw(age);
	window.draw(occupation);
	window.draw(picture);
}

void Id::LoadAssets()
{
	if (!backgroundTexture.loadFromFile(backgroundTexturePath))
		std::cout << "id backgroundTexturePath doesn't exist";

	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(Positions::IdBackground[0], Positions::IdBackground[1]);
}
