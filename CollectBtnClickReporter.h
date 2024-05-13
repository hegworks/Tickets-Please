#pragma once
#include "GameplaySettings.h"
#include <SFML/Graphics.hpp>

class CollectBtnClickReporter
{
private:
	inline static std::string spritesAddress = "Assets/2D/Mistakes";
	inline static sf::Sprite sprites[GameplaySettings::RuleEnumSize + 1];
	inline static sf::Texture textures[GameplaySettings::RuleEnumSize + 1];

public:
	static void LoadAssets();
	static void Draw(sf::RenderWindow& window, int decidedRuleIndex);
	static void Hide();
};

