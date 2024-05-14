#pragma once
#include "GameEvent.h"
#include "GameState.h"

class GameStateManager
{
public:
	inline static GameState gameState = GameState::InGameplay;

public:
	void static OnGameEvent(GameEvent gameEvent);
	void static HandleLeftMouseClicks(sf::Vector2i mousePos);
};
