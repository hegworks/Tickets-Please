#include "DateManager.h"
#include "IdPicturesDb.h"
#include "InfoRandomizer.h"
#include "Rng.h"
#include "RuleCardsMaker.h"

RuleCardsMaker::Cards RuleCardsMaker::GenerateMatchingCards()
{
	// generate Id
	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(data.personType);
	sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
	cards.id = Id(data.gender, age, data.personType, picture);

	// generate Ticket
	Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, data.gender, false, data.personType);

	return cards;
}

RuleCardsMaker::Cards RuleCardsMaker::GenerateIdTitlePictureCards()
{
	// generate Id
	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(data.personType);

	Gender wrongGender;
	if (data.gender == Gender::Male)
		wrongGender = Gender::Female;
	else
		wrongGender = Gender::Male;

	bool giveWrongGenderToTitle = Rng::BetweenInclusive(0, 1) == 0;
	Gender titleGender;
	Gender pictureGender;
	if (giveWrongGenderToTitle)
	{
		titleGender = wrongGender;
		pictureGender = data.gender;
	}
	else
	{
		titleGender = data.gender;
		pictureGender = wrongGender;
	}

	sf::Sprite picture = IdPicturesDb::GetRandomPicture(pictureGender);
	cards.id = Id(titleGender, age, data.personType, picture);

	// generate Ticket
	Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, data.gender, false, data.personType);

	return cards;
}

RuleCardsMaker::Cards RuleCardsMaker::GenerateTicketTimeCards()
{
	return Cards();
}

RuleCardsMaker::Cards RuleCardsMaker::GenerateTicketTornCards()
{
	return Cards();
}

RuleCardsMaker::Cards RuleCardsMaker::GenerateCrossStudentCards()
{
	return Cards();
}

RuleCardsMaker::Cards RuleCardsMaker::GenerateCrossElderCards()
{
	return Cards();
}
