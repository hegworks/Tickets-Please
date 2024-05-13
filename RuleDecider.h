#pragma once
#include "Rule.h"

class RuleDecider
{
private:
	inline static Rule decidedRule;

public:
	inline static Rule GetDecidedRule()
	{
		return decidedRule;
	}

	static void DecideRule();
};
