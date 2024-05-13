#pragma once
#include "Rule.h"

class RuleDecider
{
private:
	inline static Rule decidedRule;
	inline static int decidedRuleIndex;

public:
	inline static Rule GetDecidedRule()
	{
		return decidedRule;
	}

	static void DecideRule();
};
