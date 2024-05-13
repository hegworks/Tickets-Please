#pragma once
#include "Date.h"
#include <SFML/Graphics.hpp>

class DateManager
{
private:
	inline static sf::Text currentDate;

public:
	static Date GenerateDate();
	static Date GenerateDateAfter(Date date);
	static Date GenerateDateBefore(Date date);
	static void CreateCurrentDateText(Date date);
	static void DrawCurrentDate(sf::RenderWindow& window);
};

