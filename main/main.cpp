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
				window.close();

			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					sf::Vector2i mousePos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);

					GameState oldGameState = GameStateManager::gameState;
					GameStateManager::OnGameEvent(GameEvent::ClickedOnScreen);
					GameState newGameState = GameStateManager::gameState;
					if (oldGameState != newGameState)
					{
						// if clicking on screen changed the game state, then do nothing
						// this is to prevent double game state changes when player
						// clicks on a button when we are in WaitingForSkipCollectBtnReport
						// state. as it first triggers ClickedOnScreen, then ClickedOn one
						// one of the buttons
					}
					else if (ButtonsManager::HasClickedOnCollectMoney(mousePos))
					{
						GameStateManager::OnGameEvent(GameEvent::ClickedOnCollectMoneyBtn);
					}
					else if (ButtonsManager::HasClickedOnCollectTicket(mousePos))
					{
						GameStateManager::OnGameEvent(GameEvent::ClickedOnCollectTicketBtn);
					}
					else if (TimesUpMenu::HasClickedOnMainMenuBtn(mousePos))
					{
						GameStateManager::OnGameEvent(GameEvent::ClickedOnTimesUpMainMenuBtn);
					}
					else if (MainMenu::HasClickedOnNewGameBtn(mousePos))
					{
						GameStateManager::OnGameEvent(GameEvent::ClickedOnMainMenuNewGameBtn);
					}
				}
			}
		}

		Timer::Update();

		window.clear(sf::Color(115, 115, 140));

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
