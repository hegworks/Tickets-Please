#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Font
{
public:
	inline static sf::Font font;

public:
	inline static void LoadAssets()
	{
		if (!font.loadFromFile("Assets/Fonts/Roboto-Regular.ttf"))
			std::cout << "Roboto-Regular.ttf doesn't exist";
	}

	inline static void SetStyle(sf::Text& text)
	{
		text.setFont(Font::font);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(22);
		text.setFillColor(sf::Color(19, 15, 64));
	}

	inline static void SetStyle_TopTexts(sf::Text& text)
	{
		text.setFont(Font::font);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
	}

	inline static void SetStyle_TimesUpScore(sf::Text& text)
	{
		text.setFont(Font::font);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(32);
		text.setFillColor(sf::Color::White);
	}
};