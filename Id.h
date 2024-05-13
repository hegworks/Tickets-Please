#pragma once
#include "Gender.h"
#include "PersonType.h"
#include <SFML/Graphics.hpp>
#include <string>

class Id
{
private:
	sf::Text title;
	sf::Text age;
	sf::Text occupation;
	sf::Sprite picture;

	static const std::string backgroundTexturePath;
	static sf::Texture backgroundTexture;
	static sf::Sprite backgroundSprite;

public:
	Id(Gender gender, int age, PersonType personType, sf::Sprite picture);
	void Draw(sf::RenderWindow& window);
	static void LoadAssets();
	Id() = default;
};
