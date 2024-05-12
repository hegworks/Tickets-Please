#include "GameplaySettings.h"
#include "ProjectSettings.h"
#include "RuleDecider.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

void RuleDecider::DecideRule()
{
	int mismatchRand = rand() % 100;
	if (ProjectSettings::CanLog)
		std::cout << "mismatchRand: " << mismatchRand << std::endl;
	bool isMismatch = mismatchRand > GameplaySettings::MismatchChance;

	if (!isMismatch)
	{
		decidedRule = Rule::Matching;
	}
	else
	{
		// why +1: because enum 0 is Matching and 1 until GameplaySettings::RuleEnumSize are Mismatch rules
		// why -1: because we should not exceed the size of Rule Enum
		decidedRule = static_cast<Rule>((rand() % (GameplaySettings::RuleEnumSize - 1)) + 1);
	}
	if (ProjectSettings::CanLog)
		std::cout << "decidedRule: " << static_cast<int>(decidedRule) << std::endl;
}
