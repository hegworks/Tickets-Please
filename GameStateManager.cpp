#include "AudioManager.h"
#include "ButtonsManager.h"
#include "CollectBtnClickReporter.h"
#include "DateManager.h"
#include "Font.h"
#include "GameStateManager.h"
#include "IdPicturesDb.h"
#include "InfoRandomizer.h"
#include "MainMenu.h"
#include "RuleCardsMaker.h"
#include "RuleDecider.h"
#include "ScoreManager.h"
#include "Timer.h"
#include "TimesUpMenu.h"
#include <iostream>

void GameStateManager::OnGameEvent(GameEvent gameEvent)
{
	std::cout << "gameEvent:" << static_cast<int>(gameEvent) << "\n";
	std::cout << "gameState:" << static_cast<int>(gameState) << "-------\n";

	if (gameEvent == GameEvent::GameOpened)
	{
		Font::LoadAssets();
		IdPicturesDb::LoadAssets();
		Id::LoadAssets();
		Ticket::LoadAssets();
		ButtonsManager::LoadAssets();
		CollectBtnClickReporter::LoadAssets();
		ScoreManager::Initialize();
		Timer::Initialize();
		TimesUpMenu::LoadAssets();
		MainMenu::LoadAssets();
		AudioManager::LoadAssets();

		MainMenu::Show();
		AudioManager::PlayBgm();

		gameState = GameState::InMainMenu;
		return;
	}

	if (gameEvent == GameEvent::TimesUp)
	{
		TimesUpMenu::Show(ScoreManager::GetScoreInt());
		gameState = GameState::InTimesUpMenu;
		return;
	}

	switch (gameState)
	{
	case GameState::InMainMenu:
	{
		if (gameEvent == GameEvent::ClickedOnMainMenuNewGameBtn)
		{
			InfoRandomizer::GenerateCurrentDate();
			DateManager::CreateCurrentDateText(InfoRandomizer::GetCurrentDate());
			ScoreManager::ResetScore();
			CollectBtnClickReporter::Hide();
			RuleCardsMaker::NewCards();
			Timer::Start();
			MainMenu::Hide();
			AudioManager::PlayUiClick();

			gameState = GameState::InGameplay;
		}
		break;
	}
	case GameState::InGameplay:
	{
		if (gameEvent == GameEvent::ClickedOnCollectMoneyBtn)
		{
			int decidedRule = RuleDecider::GetDecidedRuleIndex();
			if (decidedRule > 0)
			{
				// player clicked correctly
				ScoreManager::IncreaseScore();
				AudioManager::PlayCorrectAnswser();
				CollectBtnClickReporter::Show(7);
			}
			else
			{
				// player clicked wrongly
				ScoreManager::DecreaseScore();
				AudioManager::PlayWrongAnswer();
				CollectBtnClickReporter::Show(decidedRule);
			}
			gameState = GameState::InGamePlayReport;
		}
		else if (gameEvent == GameEvent::ClickedOnCollectTicketBtn)
		{
			int decidedRule = RuleDecider::GetDecidedRuleIndex();
			if (decidedRule == 0)
			{
				// player clicked correctly
				ScoreManager::IncreaseScore();
				AudioManager::PlayCorrectAnswser();
				CollectBtnClickReporter::Show(7);
			}
			else
			{
				// player clicked wrongly
				ScoreManager::DecreaseScore();
				AudioManager::PlayWrongAnswer();
				CollectBtnClickReporter::Show(decidedRule);
			}
			gameState = GameState::InGamePlayReport;
		}
		break;
	}
	case GameState::InGamePlayReport:
	{
		if (gameEvent == GameEvent::ClickedOnScreen)
		{
			// CollectBtnReport was shown and user has clicked on the screen
			// so we hide the report and generate a new set of cards
			CollectBtnClickReporter::Hide();
			RuleCardsMaker::NewCards();
			AudioManager::PlayUiClick();
			gameState = GameState::InGameplay;
		}
		break;
	}
	case GameState::InTimesUpMenu:
	{
		if (gameEvent == GameEvent::ClickedOnTimesUpMainMenuBtn)
		{
			MainMenu::Show();
			TimesUpMenu::Hide();
			AudioManager::PlayUiClick();
			gameState = GameState::InMainMenu;
		}
	}
	default:
		break;
	}
}
