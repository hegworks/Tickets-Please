#include "Font.h"
#include "GameplaySettings.h"
#include "Positions.h"
#include "Timer.h"

void Timer::Initialize()
{
	eachGameTime = sf::seconds(GameplaySettings::TimeOfEachGameSeconds);
	Font::SetStyle_TopTexts(timeLeftText);
	timeLeftText.setPosition(Positions::Time[0], Positions::Time[1]);
}

void Timer::Start()
{
	clock.restart();
	timeLeft = eachGameTime;
}

void Timer::Update()
{
	timeLeft = eachGameTime - clock.getElapsedTime();
	int secondsLeft = timeLeft.asSeconds();
	int miliSeconndsLeft = timeLeft.asMilliseconds() % 1000;
	timeLeftText.setString(std::to_string(secondsLeft) + ":" + std::to_string(miliSeconndsLeft));
}

void Timer::Draw(sf::RenderWindow& window)
{
	window.draw(timeLeftText);
}
