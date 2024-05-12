#pragma once
#include "Date.h"

class DateManager
{
public:
	Date GenerateDate();
	Date GenerateDateAfter(Date date);
	Date GenerateDateBefore(Date date);
};

