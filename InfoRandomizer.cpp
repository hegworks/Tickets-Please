#include "DateManager.h"
#include "GameplaySettings.h"
#include "InfoRandomizer.h"
#include "Rng.h"
#include <iostream>
#include <stdlib.h>

InfoRandomizer::Data InfoRandomizer::data;
Date InfoRandomizer::currentDate;

void InfoRandomizer::GenerateData()
{
	// random gender
	int	genderChance = Rng::BetweenInclusive(0, 1);
	if (genderChance == 0)
		data.gender = Gender::Male;
	else
		data.gender = Gender::Female;

	// random PersonType
	int personTypeChance = Rng::BetweenInclusive(0, 2);
	if (personTypeChance == 0)
		data.personType = PersonType::Normal;
	else if (personTypeChance == 1)
		data.personType = PersonType::Student;
	else
		data.personType = PersonType::Elder;
}

void InfoRandomizer::GenerateCurrentDate()
{
	currentDate = DateManager::GenerateDate();
}

int InfoRandomizer::GenerateRandomAge(PersonType persontype)
{
	switch (persontype)
	{
	case PersonType::Normal:
		return Rng::BetweenInclusive(GameplaySettings::NormalAgeRangeStart, GameplaySettings::NormalAgeRangeEnd);
	case PersonType::Student:
		return Rng::BetweenInclusive(GameplaySettings::StudentAgeRangeStart, GameplaySettings::StudentAgeRangeEnd);
	case PersonType::Elder:
		return Rng::BetweenInclusive(GameplaySettings::ElderAgeRangeStart, GameplaySettings::ElderAgeRangeEnd);
	default:
		break;
	}
}

InfoRandomizer::Data InfoRandomizer::GetData()
{
	return data;
}

Date InfoRandomizer::GetCurrentDate()
{
	return currentDate;
}
