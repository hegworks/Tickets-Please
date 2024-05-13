#include "Gender.h"
#include "IdPicturesDb.h"
#include "Rng.h"
#include <filesystem>
#include <iostream>

std::string IdPicturesDb::malePicsAddress = "Assets/2D/malePics";
std::string IdPicturesDb::femalePicsAddress = "Assets/2D/FemalePics";

sf::Texture IdPicturesDb::maleTextures[MalePicsCount];
sf::Texture IdPicturesDb::femaleTextures[FemalePicsCount];

sf::Sprite IdPicturesDb::maleSprites[MalePicsCount];
sf::Sprite IdPicturesDb::femaleSprites[FemalePicsCount];

void IdPicturesDb::LoadAssets()
{
	LoadSpritesFromAddress(malePicsAddress, maleTextures, maleSprites);
	LoadSpritesFromAddress(femalePicsAddress, femaleTextures, femaleSprites);
}


void IdPicturesDb::LoadSpritesFromAddress(std::string address, sf::Texture textures[], sf::Sprite sprites[])
{
	int i = 0;
	for (const auto& entry : std::filesystem::directory_iterator(address))
	{
		if (!textures[i].loadFromFile(entry.path().string()))
			std::cout << "maleTextures" << i << "doesn't exist in path: " << entry.path().string() << "\n";
		textures[i].setSmooth(true);

		sf::Sprite sprite;
		sprite.setTexture(textures[i]);
		sprites[i] = sprite;
		i++;
	};
}

sf::Sprite IdPicturesDb::GetRandomPicture(Gender gender)
{
	switch (gender)
	{
	case Gender::Male:
		return maleSprites[Rng::BetweenInclusive(0, MalePicsCount - 1)];
	case Gender::Female:
		return femaleSprites[Rng::BetweenInclusive(0, FemalePicsCount - 1)];
	default:
		break;
	}
}
