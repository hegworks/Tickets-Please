#pragma once
#include <SFML/Graphics.hpp>

class Timer
{
private:
	inline static sf::Time eachGameTime;
	inline static sf::Time timeLeft;
	inline static sf::Text timeLeftText;
	inline static sf::Clock clock;
	inline static bool sentTimesUpEvent = false;

public:
	static void Initialize();
	static void Start();
	static void Update();
	static void Draw(sf::RenderWindow& window);
};

