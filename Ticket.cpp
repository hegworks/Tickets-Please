#include "Font.h"
#include "Id.h"
#include "Positions.h"
#include "Ticket.h"
#include <iostream>

const std::string Ticket::backgroundTexturePath = "Assets/2D/Ticket.png";
sf::Texture Ticket::backgroundTexture;
sf::Sprite Ticket::backgroundSprite;

const std::string Ticket::tornTexturePath = "Assets/2D/Torn.png";
sf::Texture Ticket::tornTexture;
sf::Sprite Ticket::tornSprite;

const std::string Ticket::normalPersonTypeTexturePath = "Assets/2D/normalPersonType.png";
sf::Texture Ticket::normalPersonTypeTexture;
sf::Sprite Ticket::normalPersonTypeSprite;

const std::string Ticket::studentPersonTypeTexturePath = "Assets/2D/studentPersonType.png";
sf::Texture Ticket::studentPersonTypeTexture;
sf::Sprite Ticket::studentPersonTypeSprite;

const std::string Ticket::elderPersonTypeTexturePath = "Assets/2D/elderPersonType.png";
sf::Texture Ticket::elderPersonTypeTexture;
sf::Sprite Ticket::elderPersonTypeSprite;

Ticket::Ticket(Date expiration, Gender gender, bool isTorn, PersonType personType)
{
	std::string date = std::to_string(expiration.year) + "." + std::to_string(expiration.month) + "." + std::to_string(expiration.day);
	Font::SetStyle(this->expiration);
	this->expiration.setString(date);
	this->expiration.setPosition(Positions::TicketExpiration[0], Positions::TicketExpiration[1]);

	if (gender == Gender::Male)
		this->gender.setString("M");
	else
		this->gender.setString("F");
	Font::SetStyle(this->gender);
	this->gender.setPosition(Positions::TicketGender[0], Positions::TicketGender[1]);

	this->isTorn = isTorn;

	switch (personType)
	{
	case PersonType::Normal:
		this->picture = normalPersonTypeSprite;
		break;
	case PersonType::Student:
		this->picture = studentPersonTypeSprite;
		break;
	case PersonType::Elder:
		this->picture = elderPersonTypeSprite;
		break;
	default:
		break;
	}
	this->picture.setPosition(Positions::TicketPicture[0], Positions::TicketPicture[1]);
}


void Ticket::Draw(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
	window.draw(expiration);
	window.draw(gender);
	window.draw(picture);
	if (isTorn)
	{
		window.draw(tornSprite);
	}
}

void Ticket::LoadAssets()
{
	if (!backgroundTexture.loadFromFile(backgroundTexturePath))
		std::cout << "ticket backgroundTexturePath doesn't exist";
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(Positions::TicketBackground[0], Positions::TicketBackground[1]);

	if (!tornTexture.loadFromFile(tornTexturePath))
		std::cout << "ticket tornTexturePath doesn't exist";
	tornSprite.setTexture(tornTexture);
	tornSprite.setPosition(Positions::TicketTorn[0], Positions::TicketTorn[1]);

	if (!normalPersonTypeTexture.loadFromFile(normalPersonTypeTexturePath))
		std::cout << "ticket normalPersonTypeTexturePath doesn't exist";
	normalPersonTypeSprite.setTexture(normalPersonTypeTexture);

	if (!studentPersonTypeTexture.loadFromFile(studentPersonTypeTexturePath))
		std::cout << "ticket studentPersonTypeTexturePath doesn't exist";
	studentPersonTypeSprite.setTexture(studentPersonTypeTexture);

	if (!elderPersonTypeTexture.loadFromFile(elderPersonTypeTexturePath))
		std::cout << "ticket elderPersonTypeTexturePath doesn't exist";
	elderPersonTypeSprite.setTexture(elderPersonTypeTexture);
}
