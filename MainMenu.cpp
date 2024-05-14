#include "MainMenu.h"
#include "Positions.h"
#include <iostream>

void MainMenu::LoadAssets()
{
	// background
	if (!backgroundTexture.loadFromFile(backgroundTexturePath))
		std::cout << "MainMenu backgroundTexturePath doesn't exist";
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(Positions::MainMenuBackground[0], Positions::MainMenuBackground[1]);

	// NewGame btn
	if (!newGameBtnTexture.loadFromFile(newGameBtnTexturePath))
		std::cout << "MainMenu newGameBtnTexturePath doesn't exist";
	newGameBtnSprite.setTexture(newGameBtnTexture);
	newGameBtnSprite.setPosition(Positions::MainMenuNewGameBtn[0], Positions::MainMenuNewGameBtn[1]);
}

void MainMenu::Show()
{
	canShow = true;
}

void MainMenu::Hide()
{
	canShow = false;
}

void MainMenu::Draw(sf::RenderWindow& window)
{
	if (!canShow) return;

	window.draw(backgroundSprite);
	window.draw(newGameBtnSprite);
}

void MainMenu::DrawBackground(sf::RenderWindow& window)
{
	window.draw(backgroundSprite);
}

bool MainMenu::HasClickedOnNewGameBtn(sf::Vector2i mousePos)
{
	if (!canShow) return false;

	return newGameBtnSprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}
