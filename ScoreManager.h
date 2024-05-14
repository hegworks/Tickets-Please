#pragma once
#include <SFML/Graphics.hpp>
class ScoreManager
{
private:
	inline static int scoreInt;
	inline static sf::Text scoreText;

public:
	static void Initialize();
	static void IncreaseScore();
	static void DecreaseScore();
	static void ResetScore();
	static void Draw(sf::RenderWindow& window);
};

