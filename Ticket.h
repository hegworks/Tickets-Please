#pragma once
#include "Date.h"
#include "Gender.h"
#include "PersonType.h"
#include <SFML/Graphics.hpp>

class Ticket
{
private:
	sf::Text expiration;
	sf::Text gender;
	bool isTorn = false;
	sf::Sprite picture;

	static const std::string backgroundTexturePath;
	static sf::Texture backgroundTexture;
	static sf::Sprite backgroundSprite;

	static const std::string tornTexturePath;
	static sf::Texture tornTexture;
	static sf::Sprite tornSprite;

	static const std::string normalPersonTypeTexturePath;
	static sf::Texture normalPersonTypeTexture;
	static sf::Sprite normalPersonTypeSprite;

	static const std::string studentPersonTypeTexturePath;
	static sf::Texture studentPersonTypeTexture;
	static sf::Sprite studentPersonTypeSprite;

	static const std::string elderPersonTypeTexturePath;
	static sf::Texture elderPersonTypeTexture;
	static sf::Sprite elderPersonTypeSprite;

public:
	Ticket(Date expiration, Gender gender, bool isTorn, PersonType personType);
	void Draw(sf::RenderWindow& window);
	static void LoadAssets();
	Ticket() = default;
};

