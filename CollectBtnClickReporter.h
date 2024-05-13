#pragma once
#include "GameplaySettings.h"
#include <SFML/Graphics.hpp>

class CollectBtnClickReporter
{
private:
	inline static std::string spritesAddress = "Assets/2D/Mistakes";
	inline static sf::Sprite sprites[GameplaySettings::RuleEnumSize + 1];
	inline static sf::Texture textures[GameplaySettings::RuleEnumSize + 1];
	//inline static sf::RenderWindow* window;
	inline static int reportIndex;
	inline static bool canShow;

public:
	static void LoadAssets();
	//static void Initialize(sf::RenderWindow& renderWindow);
	static void Draw(sf::RenderWindow& renderWindow);
	static void Show(int reportIndex);
	static void Hide();
};

