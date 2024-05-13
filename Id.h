#pragma once
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
	Id(std::string title, int age, std::string occupation, sf::Sprite picture);
	void Draw(sf::RenderWindow& window);
	static void LoadAssets();
};
