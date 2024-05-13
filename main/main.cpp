#include "../DateManager.h"
#include "../Font.h"
#include "../Id.h"
#include "../IdPicturesDb.h"
#include "../InfoRandomizer.h"
#include "../ProjectSettings.h"
#include "../Rng.h"
#include "../Rule.h"
#include "../RuleDecider.h"
#include "../Ticket.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tickets, Please", sf::Style::Close | sf::Style::Titlebar);


	srand(time(0));


	Font::LoadAssets();
	IdPicturesDb::LoadAssets();
	Id::LoadAssets();
	Ticket::LoadAssets();


	InfoRandomizer::GenerateCurrentDate();

	InfoRandomizer::GenerateData();
	RuleDecider::DecideRule();

	Id id;
	Ticket ticket;
	if (RuleDecider::GetDecidedRule() == Rule::Matching)
	{
		// generate Id
		InfoRandomizer::Data data = InfoRandomizer::GetData();
		int age = InfoRandomizer::GenerateRandomAge(data.personType);
		sf::Sprite picture = IdPicturesDb::GetRandomPicture(data.gender);
		id = Id(data.gender, age, data.personType, picture);

		// generate Ticket
		Date date = DateManager::GenerateDateAfter(InfoRandomizer::GetCurrentDate());
		ticket = Ticket(date, data.gender, false, data.personType);
	}


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(115, 115, 140));
		id.Draw(window);
		ticket.Draw(window);
		window.display();
	}

	return 0;
}