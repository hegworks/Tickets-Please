#pragma once
#include "Date.h"

class DateManager
{
public:
	static Date GenerateDate();
	static Date GenerateDateAfter(Date date);
	static Date GenerateDateBefore(Date date);
};

