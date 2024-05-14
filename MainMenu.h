#pragma once
#include <SFML/Graphics.hpp>
class MainMenu
{
private:
	inline static const std::string backgroundTexturePath = "Assets/2D/MainMenuBackground.png";
	inline static sf::Texture backgroundTexture;
	inline static sf::Sprite backgroundSprite;

	inline static const std::string newGameBtnTexturePath = "Assets/2D/NewGameBtn.png";
	inline static sf::Texture newGameBtnTexture;
	inline static sf::Sprite newGameBtnSprite;

	inline static bool canShow = false;

public:
	static void LoadAssets();
	static void Show();
	static void Hide();
	static void Draw(sf::RenderWindow& window);
	static bool HasClickedOnNewGameBtn(sf::Vector2i mousePos);
};

