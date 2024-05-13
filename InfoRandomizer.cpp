#include "DateManager.h"
#include "InfoRandomizer.h"
#include <stdlib.h>

InfoRandomizer::Data InfoRandomizer::data;
Date InfoRandomizer::currentDate;

void InfoRandomizer::GenerateData()
{
	// random gender
	int	genderChance = rand() % 2;
	if (genderChance == 0)
		data.gender = Gender::Male;
	else
		data.gender = Gender::Female;

	// random PersonType
	int personTypeChance = rand() % 3;
	if (genderChance == 0)
		data.personType = PersonType::Normal;
	else if (genderChance == 1)
		data.personType = PersonType::Student;
	else
		data.personType = PersonType::Elder;

	//// random valid expiration Date
	//DateManager dm;
	//data.expiration = dm.GenerateDateAfter(currentDate);

	//// not torn ticket
	//data.isTorn = false;


}

void InfoRandomizer::GenerateCurrentDate()
{
	currentDate = DateManager::GenerateDate();
}

InfoRandomizer::Data InfoRandomizer::GetData()
{
	return data;
}

Date InfoRandomizer::GetCurrentDate()
{
	return currentDate;
}
