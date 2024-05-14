#pragma once
#include <SFML/Graphics.hpp>

class TimesUpMenu
{
private:
	inline static const std::string backgroundTexturePath = "Assets/2D/TimesUp.png";
	inline static sf::Texture backgroundTexture;
	inline static sf::Sprite backgroundSprite;

	inline static const std::string mainMenuBtnTexturePath = "Assets/2D/TimesUpMainMenuBtn.png";
	inline static sf::Texture mainMenuBtnTexture;
	inline static sf::Sprite mainMenuBtnSprite;

	inline static sf::Text scoreText;

	inline static bool canShow = false;

public:
	static void LoadAssets();
	static void Show(int score);
	static void Hide();
	static void Draw(sf::RenderWindow& window);
	static bool HasClickedOnMainMenuBtn(sf::Vector2i mousePos);
};

