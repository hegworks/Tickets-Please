#include "DateManager.h"
#include "IdPicturesDb.h"
#include "InfoRandomizer.h"
#include "Rng.h"
#include "RuleCardsMaker.h"

/// <summary>
/// every field matches
/// </summary>
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

/// <summary>
/// IdTitle != IdPicture
/// </summary>
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

/// <summary>
/// TicketDate < CurrentDate
/// </summary>
RuleCardsMaker::Cards RuleCardsMaker::GenerateTicketDateCards()
{
	// generate Id
	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(data.personType);
	sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
	cards.id = Id(data.gender, age, data.personType, picture);

	// generate Ticket
	Date date = DateManager::GenerateDateBefore(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, data.gender, false, data.personType);

	return cards;
}

/// <summary>
/// Ticket isTorn
/// </summary>
RuleCardsMaker::Cards RuleCardsMaker::GenerateTicketTornCards()
{
	// generate Id
	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(data.personType);
	sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
	cards.id = Id(data.gender, age, data.personType, picture);

	// generate Ticket
	Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, data.gender, true, data.personType);

	return cards;
}

RuleCardsMaker::Cards RuleCardsMaker::GenerateTicketGenderCards()
{
	// generate Id
	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(data.personType);
	sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
	cards.id = Id(data.gender, age, data.personType, picture);

	// generate Ticket
	Gender wrongGender;
	if (data.gender == Gender::Male)
		wrongGender = Gender::Female;
	else
		wrongGender = Gender::Male;
	Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, wrongGender, false, data.personType);

	return cards;
}

/// <summary>
/// TicketPersonType is Student but
/// IdPersonType is not Student
/// </summary>
RuleCardsMaker::Cards RuleCardsMaker::GenerateCrossStudentCards()
{
	// generate Id
	PersonType idPersonType;
	int randomNotStudent = Rng::BetweenInclusive(0, 1) == 0;
	if (randomNotStudent == 0)
		idPersonType = PersonType::Normal;
	else
		idPersonType = PersonType::Elder;

	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(idPersonType);
	sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
	cards.id = Id(data.gender, age, idPersonType, picture);

	// generate Ticket
	Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, data.gender, false, PersonType::Student);

	return cards;
}

/// <summary>
/// TicketPersonType is Elder but
/// IdPersonType is not Elder
/// </summary>
RuleCardsMaker::Cards RuleCardsMaker::GenerateCrossElderCards()
{
	// generate Id
	PersonType idPersonType;
	int randomNotStudent = Rng::BetweenInclusive(0, 1) == 0;
	if (randomNotStudent == 0)
		idPersonType = PersonType::Normal;
	else
		idPersonType = PersonType::Student;

	InfoRandomizer::Data data = InfoRandomizer::GetData();
	int age = InfoRandomizer::GenerateRandomAge(idPersonType);
	sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
	cards.id = Id(data.gender, age, idPersonType, picture);

	// generate Ticket
	Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
	cards.ticket = Ticket(date, data.gender, false, PersonType::Elder);

	return cards;
}
