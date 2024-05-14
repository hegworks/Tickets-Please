#include "ButtonsManager.h"
#include "GameStateManager.h"
#include "Positions.h"
#include <iostream>

void ButtonsManager::LoadAssets()
{
	// collectMoney
	if (!collectMoneyTexture.loadFromFile(collectMoneyTexturePath))
		std::cout << "collectMoneyTexturePath doesn't exist";
	collectMoneySprite.setTexture(collectMoneyTexture);
	collectMoneySprite.setPosition(Positions::CollectMoney[0], Positions::CollectMoney[1]);

	// collectTicket
	if (!collectTicketTexture.loadFromFile(collectTicketTexturePath))
		std::cout << "collectTicketTexturePath doesn't exist";
	collectTicketSprite.setTexture(collectTicketTexture);
	collectTicketSprite.setPosition(Positions::CollectTicket[0], Positions::CollectTicket[1]);
}

void ButtonsManager::Draw(sf::RenderWindow& window)
{
	window.draw(collectMoneySprite);
	window.draw(collectTicketSprite);
}

bool ButtonsManager::HasClickedOnCollectMoney(sf::Vector2i mousePos)
{
	if (GameStateManager::gameState != GameState::WaitingForCollectBtnClick) return false;

	return collectMoneySprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

bool ButtonsManager::HasClickedOnCollectTicket(sf::Vector2i mousePos)
{
	if (GameStateManager::gameState != GameState::WaitingForCollectBtnClick) return false;

	return collectTicketSprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}
