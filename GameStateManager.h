#pragma once
#include "GameEvent.h"
#include "GameState.h"

class GameStateManager
{
public:
	inline static GameState gameState = GameState::WaitingForCollectBtnClick;

public:
	void static OnGameEvent(GameEvent gameEvent);
};
