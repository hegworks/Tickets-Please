#include "../ButtonsManager.h"
#include "../CollectBtnClickReporter.h"
#include "../DateManager.h"
#include "../GameStateManager.h"
#include "../MainMenu.h"
#include "../RuleCardsMaker.h"
#include "../ScoreManager.h"
#include "../Timer.h"
#include "../TimesUpMenu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Tickets, Please", sf::Style::Close | sf::Style::Titlebar);

	GameStateManager::OnGameEvent(GameEvent::GameOpened);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				continue;
			}

			if (event.type != sf::Event::MouseButtonPressed)
				continue;

			if (event.mouseButton.button != sf::Mouse::Left)
				continue;

			sf::Vector2i mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
			GameStateManager::HandleLeftMouseClicks(mousePos);
		}

		Timer::Update();

		window.clear();

		MainMenu::DrawBackground(window);
		RuleCardsMaker::cards.id.Draw(window);
		RuleCardsMaker::cards.ticket.Draw(window);
		DateManager::DrawCurrentDate(window);
		ScoreManager::Draw(window);
		Timer::Draw(window);
		ButtonsManager::Draw(window);
		CollectBtnClickReporter::Draw(window);
		TimesUpMenu::Draw(window);
		MainMenu::Draw(window);

		window.display();
	}

	return 0;
}
