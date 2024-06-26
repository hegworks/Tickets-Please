#include "GameplaySettings.h"
#include "ProjectSettings.h"
#include "Rng.h"
#include "RuleDecider.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

void RuleDecider::DecideRule()
{
	int mismatchRand = Rng::BetweenInclusive(1, 100);
	if (ProjectSettings::CanLog)
		std::cout << "mismatchRand: " << mismatchRand << std::endl;
	bool isMismatch = mismatchRand > GameplaySettings::MismatchChance;

	if (!isMismatch)
	{
		decidedRule = Rule::Matching;
		decidedRuleIndex = 0;
	}
	else
	{
		int randomRuleNumber = Rng::BetweenInclusive(1, GameplaySettings::RuleEnumSize - 1);
		decidedRule = static_cast<Rule>(randomRuleNumber);
		decidedRuleIndex = randomRuleNumber;
	}
	if (ProjectSettings::CanLog)
		std::cout << "decidedRule: " << static_cast<int>(decidedRule) << std::endl;
}
