#include "../ButtonsManager.h"
#include "../DateManager.h"
#include "../Font.h"
#include "../Id.h"
#include "../IdPicturesDb.h"
#include "../InfoRandomizer.h"
#include "../ProjectSettings.h"
#include "../Rng.h"
#include "../Rule.h"
#include "../RuleCardsMaker.h"
#include "../RuleDecider.h"
#include "../Ticket.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tickets, Please", sf::Style::Close | sf::Style::Titlebar);


	Font::LoadAssets();
	IdPicturesDb::LoadAssets();
	Id::LoadAssets();
	Ticket::LoadAssets();
	ButtonsManager::LoadAssets();


	InfoRandomizer::GenerateCurrentDate();
	DateManager::CreateCurrentDateText(InfoRandomizer::GetCurrentDate());

	InfoRandomizer::GenerateData();
	RuleDecider::DecideRule();

	Id id;
	Ticket ticket;
	RuleCardsMaker::Cards cards;

	switch (RuleDecider::GetDecidedRule())
	{
	case Rule::Matching:
		cards = RuleCardsMaker::GenerateMatchingCards();
		break;
	case Rule::IdTitlePicture:
		cards = RuleCardsMaker::GenerateIdTitlePictureCards();
		break;
	case Rule::TicketDate:
		cards = RuleCardsMaker::GenerateTicketDateCards();
		break;
	case Rule::TicketTorn:
		cards = RuleCardsMaker::GenerateTicketTornCards();
		break;
	case Rule::TicketGender:
		cards = RuleCardsMaker::GenerateTicketGenderCards();
		break;
	case Rule::CrossStudent:
		cards = RuleCardsMaker::GenerateCrossStudentCards();
		break;
	case Rule::CrossElder:
		cards = RuleCardsMaker::GenerateCrossElderCards();
		break;
	default:
		break;
	}
	id = cards.id;
	ticket = cards.ticket;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
					if (ButtonsManager::HasClickedOnCollectMoney(mousePos))
					{
						std::cout << "clicked on collect money\n";
					}
					else if (ButtonsManager::HasClickedOnCollectTicket(mousePos))
					{
						std::cout << "clicked on collect ticket\n";
					}
				}
			}
		}

		window.clear(sf::Color(115, 115, 140));
		id.Draw(window);
		ticket.Draw(window);
		DateManager::DrawCurrentDate(window);
		ButtonsManager::Draw(window);
		window.display();
	}

	return 0;
}
