#pragma once
#include "Rule.h"

class RuleDecider
{
private:
	Rule decidedRule;

public:
	Rule GetDecidedRule()
	{
		return decidedRule;
	}

	void DecideRule();
};
