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
	inline static int GetDecidedRuleIndex()
	{
		return decidedRuleIndex;
	}

	static void DecideRule();
};
