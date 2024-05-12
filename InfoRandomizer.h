#pragma once
#include "Date.h"
#include "Gender.h"
#include "PersonType.h"

class InfoRandomizer
{
	struct Data
	{
		Gender gender;
		PersonType personType;
		/*Date expiration;
		bool isTorn;*/
	};

private:
	Data data;
	Date currentDate;

public:
	void GenerateData();
	void GenerateCurrentDate();
	Data GetData();
	Date GetCurrentDate();
};

