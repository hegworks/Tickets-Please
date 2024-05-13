#pragma once
#include <SFML/Graphics.hpp>
class ButtonsManager
{
private:
	inline static const std::string collectTicketTexturePath = "Assets/2D/CollectTicket.png";
	inline static sf::Texture collectTicketTexture;
	inline static sf::Sprite collectTicketSprite;

	inline static const std::string collectMoneyTexturePath = "Assets/2D/CollectMoney.png";
	inline static sf::Texture collectMoneyTexture;
	inline static sf::Sprite collectMoneySprite;

public:
	static void LoadAssets();
	static void Draw(sf::RenderWindow& window);
	static bool HasClickedOnCollectMoney(sf::Vector2i mousePos);
	static bool HasClickedOnCollectTicket(sf::Vector2i mousePos);
};
