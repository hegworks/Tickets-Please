#pragma once
#include "Date.h"
#include "Gender.h"
#include "PersonType.h"

class InfoRandomizer
{
public:
	struct Data
	{
		Gender gender;
		PersonType personType;
	};

private:
	static Data data;
	static Date currentDate;

public:
	static void GenerateData();
	static void GenerateCurrentDate();
	static int GenerateRandomAge(PersonType persontype);
	static Data GetData();
	static Date GetCurrentDate();
};

