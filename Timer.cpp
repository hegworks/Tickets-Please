#include "Font.h"
#include "GameplaySettings.h"
#include "GameStateManager.h"
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
	sentTimesUpEvent = false;
}

void Timer::Update()
{
	if (sentTimesUpEvent) return;

	timeLeft = eachGameTime - clock.getElapsedTime();

	if (timeLeft.asMilliseconds() <= 0)
	{
		GameStateManager::OnGameEvent(GameEvent::TimesUp);
		sentTimesUpEvent = true;
		timeLeftText.setString("00:000");
		return;
	}

	int secondsLeft = timeLeft.asSeconds();
	int miliSeconndsLeft = timeLeft.asMilliseconds() % 1000;
	timeLeftText.setString(std::to_string(secondsLeft) + ":" + std::to_string(miliSeconndsLeft));
}

void Timer::Draw(sf::RenderWindow& window)
{
	window.draw(timeLeftText);
}
