#pragma once
#include <random>
class Rng {
public:
	int BetweenInclusive(int a, int b)
	{
		std::random_device seed;
		std::mt19937 mt(seed());
		std::uniform_int_distribution<> uid(a, b); // range
		return uid(mt);
	}
};