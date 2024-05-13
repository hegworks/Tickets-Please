#pragma once
#include "Id.h"
#include "Ticket.h"
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
	static Cards GenerateTicketTimeCards();
	static Cards GenerateTicketTornCards();
	static Cards GenerateCrossStudentCards();
	static Cards GenerateCrossElderCards();
};

