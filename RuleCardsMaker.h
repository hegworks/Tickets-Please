#pragma once
#include "Id.h"
#include "Ticket.h"

/// <summary>
/// constructs Id & Ticket cards based on the rule decided by RuleDecider
/// </summary>
class RuleCardsMaker
{
public:
	struct Cards
	{
		Ticket ticket;
		Id id;
	};

public:
	inline static Cards cards;

public:
	static Cards GenerateMatchingCards();
	static Cards GenerateIdTitlePictureCards();
	static Cards GenerateTicketDateCards();
	static Cards GenerateTicketTornCards();
	static Cards GenerateCrossStudentCards();
	static Cards GenerateCrossElderCards();
};

