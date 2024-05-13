#include "GameplaySettings.h"
#include "ProjectSettings.h"
#include "Rng.h"
#include "RuleDecider.h"
#include <cstdlib>
#include <iostream>
#include <time.h>

void RuleDecider::DecideRule()
{
	int mismatchRand = rand() % 100;
	if (ProjectSettings::CanLog)
		std::cout << "mismatchRand: " << mismatchRand << std::endl;
	//bool isMismatch = mismatchRand > GameplaySettings::MismatchChance;
	bool isMismatch = true;

	if (!isMismatch)
	{
		decidedRule = Rule::Matching;
	}
	else
	{
		int randomRuleNumber = Rng::BetweenInclusive(1, GameplaySettings::RuleEnumSize - 1);
		//decidedRule = static_cast<Rule>(randomRuleNumber);
		decidedRule = static_cast<Rule>(1);
	}
	if (ProjectSettings::CanLog)
		std::cout << "decidedRule: " << static_cast<int>(decidedRule) << std::endl;
}
