#pragma once
#include <filesystem>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

class IdPicturesDb
{
public:
	static const int MalePicsCount = 5;
	static const int FemalePicsCount = 4;

	static sf::Sprite maleSprites[MalePicsCount];
	static sf::Sprite femaleSprites[FemalePicsCount];

private:
	static std::string malePicsAddress;
	static std::string femalePicsAddress;

	static sf::Texture maleTextures[MalePicsCount];
	static sf::Texture femaleTextures[FemalePicsCount];

public:
	static void LoadAssets();
	static sf::Sprite GetRandomPicture(Gender gender);

private: static void LoadSpritesFromAddress(std::string address, sf::Texture textures[], sf::Sprite sprites[]);
};