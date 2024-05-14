#include "Font.h"
#include "Positions.h"
#include "TimesUpMenu.h"
#include <iostream>

void TimesUpMenu::LoadAssets()
{
	// background
	if (!backgroundTexture.loadFromFile(backgroundTexturePath))
		std::cout << "TimesUpMenu backgroundTexturePath doesn't exist\n";
	backgroundSprite.setTexture(backgroundTexture);
	backgroundSprite.setPosition(Positions::TimesUpBackground[0], Positions::TimesUpBackground[1]);

	// main menu btn
	if (!mainMenuBtnTexture.loadFromFile(mainMenuBtnTexturePath))
		std::cout << "TimesUpMenu mainMenuBtnTexturePath doesn't exist\n";
	mainMenuBtnSprite.setTexture(mainMenuBtnTexture);
	mainMenuBtnSprite.setPosition(Positions::TimesUpMainMenuBtn[0], Positions::TimesUpMainMenuBtn[1]);

	// scoreText
	Font::SetStyle_TimesUpScore(scoreText);
}

void TimesUpMenu::Show(int score)
{
	scoreText.setString(std::to_string(score));
	scoreText.setOrigin(scoreText.getGlobalBounds().getSize() / 2.0f + scoreText.getLocalBounds().getPosition());
	scoreText.setPosition(Positions::TimesUpScore[0], Positions::TimesUpScore[1]);
	canShow = true;
}

void TimesUpMenu::Hide()
{
	canShow = false;
}

void TimesUpMenu::Draw(sf::RenderWindow& window)
{
	if (canShow)
	{
		window.draw(backgroundSprite);
		window.draw(scoreText);
		window.draw(mainMenuBtnSprite);
	}
}

bool TimesUpMenu::HasClickedOnMainMenuBtn(sf::Vector2i mousePos)
{
	if (!canShow) return false;

	return mainMenuBtnSprite.getGlobalBounds().contains(mousePos.x, mousePos.y);
}
