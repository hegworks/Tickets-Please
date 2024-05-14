#include "AudioManager.h"
#include "CollectBtnClickReporter.h"
#include "DateManager.h"
#include "GameStateManager.h"
#include "InfoRandomizer.h"
#include "main.h"
#include "MainMenu.h"
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
		MainMenu::Show();
		AudioManager::PlayBgm();

		gameState = GameState::InMainMenu;
		return;
	}

	if (gameEvent == GameEvent::TimesUp)
	{
		TimesUpMenu::Show(ScoreManager::GetScoreInt());
		gameState = GameState::WaitingForTimesUpMenuBtnClick;
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
			main::NewCards();
			Timer::Start();
			MainMenu::Hide();

			gameState = GameState::WaitingForCollectBtnClick;
		}
		break;
	}
	case GameState::WaitingForCollectBtnClick:
	{
		if (gameEvent == GameEvent::ClickedOnCollectMoneyBtn)
		{
			int decidedRule = RuleDecider::GetDecidedRuleIndex();
			if (decidedRule > 0)
			{
				// player clicked correctly
				ScoreManager::IncreaseScore();
				CollectBtnClickReporter::Show(7);
			}
			else
			{
				// player clicked wrongly
				ScoreManager::DecreaseScore();
				CollectBtnClickReporter::Show(decidedRule);
			}
			gameState = GameState::WaitingForSkipCollectBtnReport;
		}
		else if (gameEvent == GameEvent::ClickedOnCollectTicketBtn)
		{
			int decidedRule = RuleDecider::GetDecidedRuleIndex();
			if (decidedRule == 0)
			{
				// player clicked correctly
				ScoreManager::IncreaseScore();
				CollectBtnClickReporter::Show(7);
			}
			else
			{
				// player clicked wrongly
				ScoreManager::DecreaseScore();
				CollectBtnClickReporter::Show(decidedRule);
			}
			gameState = GameState::WaitingForSkipCollectBtnReport;
		}
		break;
	}
	case GameState::WaitingForSkipCollectBtnReport:
	{
		if (gameEvent == GameEvent::ClickedOnScreen)
		{
			// CollectBtnReport was shown and user has clicked on the screen
			// so we hide the report and generate a new set of cards
			CollectBtnClickReporter::Hide();
			main::NewCards();
			gameState = GameState::WaitingForCollectBtnClick;
		}
		break;
	}
	case GameState::WaitingForTimesUpMenuBtnClick:
	{
		if (gameEvent == GameEvent::ClickedOnTimesUpMainMenuBtn)
		{
			MainMenu::Show();
			TimesUpMenu::Hide();
			gameState = GameState::InMainMenu;
		}
	}
	default:
		break;
	}
}
