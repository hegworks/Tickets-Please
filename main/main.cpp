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

	InfoRandomizer::GenerateData();

	RuleDecider ruleDecider{};
	ruleDecider.DecideRule();

	IdPicturesDb::LoadAssets();
	IdPicturesDb::maleSprites[0].setPosition(250, 250);
	IdPicturesDb::maleSprites[1].setPosition(350, 250);
	IdPicturesDb::femaleSprites[2].setPosition(450, 250);


	Id::LoadAssets();
	Id id("Hooman", 24, "student", IdPicturesDb::maleSprites[2]);

	Date date = DateManager::GenerateDate();

	Ticket::LoadAssets();
	Ticket ticket(date, Gender::Male, false, PersonType::Student);


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