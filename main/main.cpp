#include "../InfoRandomizer.h"
#include "../ProjectSettings.h"
#include "../Rng.h"
#include "../Rule.h"
#include "../RuleDecider.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	srand(time(0));

	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tickets, Please", sf::Style::Close | sf::Style::Titlebar);


	const int FIXED_Y_OFFSET = -50;
	const int BETWEEN_CARDS_Y_OFFSET = 10;
	const int CARDS_BUTTONS_Y_OFFSET = 20;
	const int BETWEEN_BUTTONS_X_OFFSET = 10;

	// =====================================
	sf::Texture idCardTexture;
	if (!idCardTexture.loadFromFile("Assets/2D/IdCard.png"))
	{
		std::cout << "IdCard.png doesn't exist";
	}

	sf::Sprite idCardsprite;
	idCardsprite.setTexture(idCardTexture);
	idCardsprite.setOrigin(idCardTexture.getSize().x / 2, idCardTexture.getSize().y / 2);
	int idCardPosY = ProjectSettings::WindowSize::Y / 2 - idCardTexture.getSize().y / 2 + FIXED_Y_OFFSET;
	idCardsprite.setPosition(ProjectSettings::WindowSize::X / 2, idCardPosY);
	// =====================================





	// =====================================
	sf::Texture ticketTexture;
	if (!ticketTexture.loadFromFile("Assets/2D/Ticket.png"))
	{
		std::cout << "Ticket.png doesn't exist";
	}

	sf::Sprite ticketSprite;
	ticketSprite.setTexture(ticketTexture);
	ticketSprite.setOrigin(ticketTexture.getSize().x / 2, ticketTexture.getSize().y / 2);
	int ticketPosY = idCardPosY = ProjectSettings::WindowSize::Y / 2 + ticketTexture.getSize().y / 2 + FIXED_Y_OFFSET + BETWEEN_CARDS_Y_OFFSET;
	ticketSprite.setPosition(ProjectSettings::WindowSize::X / 2, ticketPosY);
	// =====================================




	// =====================================
	sf::Texture collectTicketTexture;
	if (!collectTicketTexture.loadFromFile("Assets/2D/CollectTicket.png"))
	{
		std::cout << "CollectTicket.png doesn't exist";
	}

	sf::Sprite collectTicketSprite;
	collectTicketSprite.setTexture(collectTicketTexture);
	collectTicketSprite.setOrigin(collectTicketTexture.getSize().x / 2, collectTicketTexture.getSize().y / 2);
	collectTicketSprite.setPosition(ProjectSettings::WindowSize::X / 2 + collectTicketTexture.getSize().x / 2 + BETWEEN_BUTTONS_X_OFFSET,
		ticketPosY + ticketTexture.getSize().y / 2 + collectTicketTexture.getSize().y / 2 + CARDS_BUTTONS_Y_OFFSET);
	// =====================================




	// =====================================
	sf::Texture collectMoneyTexture;
	if (!collectMoneyTexture.loadFromFile("Assets/2D/CollectMoney.png"))
	{
		std::cout << "CollectMoney.png doesn't exist";
	}

	sf::Sprite collectMoneySprite;
	collectMoneySprite.setTexture(collectMoneyTexture);
	collectMoneySprite.setOrigin(collectMoneyTexture.getSize().x / 2, collectMoneyTexture.getSize().y / 2);
	collectMoneySprite.setPosition(ProjectSettings::WindowSize::X / 2 - collectMoneyTexture.getSize().x / 2 - BETWEEN_BUTTONS_X_OFFSET,
		ticketPosY + ticketTexture.getSize().y / 2 + collectMoneyTexture.getSize().y / 2 + CARDS_BUTTONS_Y_OFFSET);
	// =====================================



	// =====================================
	sf::Font font;
	if (!font.loadFromFile("Assets/Fonts/Roboto-Regular.ttf"))
	{
		std::cout << "Roboto-Regular.ttf doesn't exist";
	}
	// =====================================

	// =====================================
	sf::Text scoreText;
	scoreText.setFont(font);
	scoreText.setString("Score: ");
	scoreText.setPosition(ProjectSettings::WindowSize::X / 2 - ticketTexture.getSize().x / 2, 10);
	// =====================================



	InfoRandomizer infoRandomizer{};
	infoRandomizer.GenerateData();

	RuleDecider ruleDecider{};
	ruleDecider.DecideRule();






	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(115, 115, 140));
		window.draw(scoreText);
		window.draw(idCardsprite);
		window.draw(ticketSprite);
		window.draw(collectTicketSprite);
		window.draw(collectMoneySprite);
		window.display();
	}

	return 0;
}