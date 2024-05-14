#include "CollectBtnClickReporter.h"
#include "GameStateManager.h"
#include "main.h"
#include "RuleDecider.h"
#include "ScoreManager.h"
#include <iostream>

void GameStateManager::OnGameEvent(GameEvent gameEvent)
{
	std::cout << "gameEvent:" << static_cast<int>(gameEvent) << "\n";
	std::cout << "gameState:" << static_cast<int>(gameState) << "-------\n";
	switch (gameState)
	{
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
	default:
		break;
	}
}
