#include "DateManager.h"
#include "Font.h"
#include "GameplaySettings.h"
#include "Positions.h"
#include "Rng.h"
#include <random>
#include <stdlib.h>

Date DateManager::GenerateDate()
{
	Rng rng;
	Date newDate;
	newDate.year = rng.BetweenInclusive(GameplaySettings::DateYearRangeStart, GameplaySettings::DateYearRangeEnd);
	newDate.month = rng.BetweenInclusive(1, 12);
	newDate.day = rng.BetweenInclusive(1, 30);
	return newDate;

}

Date DateManager::GenerateDateAfter(Date date)
{
	// generate randomly
	Rng rng;
	Date newDate;
	newDate.year = rng.BetweenInclusive(date.year, date.year + 3);
	newDate.month = rng.BetweenInclusive(date.month, 12);
	newDate.day = rng.BetweenInclusive(date.day, 30);

	// if the exact same, add at least 1 day to the newDate
	if (newDate.day == date.day && newDate.month == date.month && newDate.year == date.year)
	{
		if (newDate.day != 30)
			newDate.day++;
		else if (newDate.month != 12)
			newDate.month++;
		else
			newDate.year++;
	}

	return newDate;
}

Date DateManager::GenerateDateBefore(Date date)
{
	// generate randomly
	Rng rng;
	Date newDate;
	newDate.year = rng.BetweenInclusive(date.year - 8, date.year);
	newDate.month = rng.BetweenInclusive(1, date.month);
	newDate.day = rng.BetweenInclusive(1, date.day);

	// if the exact same, subtract at least 1 day from the newDate
	if (newDate.day == date.day && newDate.month == date.month && newDate.year == date.year)
	{
		if (newDate.day != 1)
			newDate.day--;
		else if (newDate.month != 1)
			newDate.month--;
		else
			newDate.year--;
	}
	return newDate;
}

void DateManager::CreateCurrentDateText(Date date)
{
	std::string dateString = std::to_string(date.year) + "." + std::to_string(date.month) + "." + std::to_string(date.day);
	Font::SetStyle_TopTexts(currentDate);
	currentDate.setString(dateString);
	currentDate.setPosition(Positions::CurrentDate[0], Positions::CurrentDate[1]);
}

void DateManager::DrawCurrentDate(sf::RenderWindow& window)
{
	window.draw(currentDate);
}


