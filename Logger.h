#pragma once
#include "ProjectSettings.h"
#include <iostream>
#include <string>

class Logger
{
public:
	void Log(std::string text) {
		if (!ProjectSettings::CanLog) return;

		std::cout << text << std::endl;
	}
};

