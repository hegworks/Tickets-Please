#pragma once
class GameplaySettings {
public:
	static const int MismatchChance = 50;

	static const int RuleEnumSize = 7;

	static const int DateYearRangeStart = 1901;
	static const int DateYearRangeEnd = 2099;

	static const int StudentAgeRangeStart = 7;
	static const int StudentAgeRangeEnd = 30;

	static const int ElderAgeRangeStart = 55;
	static const int ElderAgeRangeEnd = 99;

	static const int NormalAgeRangeStart = 18;
	static const int NormalAgeRangeEnd = 54;

	static const int ScoreIncreaseAmount = 100;
	static const int ScoreDecreaseAmount = 50;

	static const int TimeOfEachGameSeconds = 3;
};