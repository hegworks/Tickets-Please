#include "Font.h"
#include "GameplaySettings.h"
#include "Positions.h"
#include "ScoreManager.h"

void ScoreManager::Initialize()
{
	scoreInt = 0;
	Font::SetStyle_TopTexts(scoreText);
	scoreText.setString("0");
	scoreText.setPosition(Positions::Score[0], Positions::Score[1]);
}

void ScoreManager::IncreaseScore()
{
	scoreInt += GameplaySettings::ScoreIncreaseAmount;
	scoreText.setString(std::to_string(scoreInt));
}

void ScoreManager::DecreaseScore()
{
	scoreInt -= GameplaySettings::ScoreDecreaseAmount;
	scoreText.setString(std::to_string(scoreInt));
}

void ScoreManager::ResetScore()
{
	scoreInt = 0;
	scoreText.setString("0");
}

void ScoreManager::Draw(sf::RenderWindow& window)
{
	window.draw(scoreText);
}
