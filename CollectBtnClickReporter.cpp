#include "CollectBtnClickReporter.h"
#include "Positions.h"
#include "Rule.h"
#include <filesystem>
#include <iostream>

void CollectBtnClickReporter::LoadAssets()
{
	int i = 0;
	for (const auto& entry : std::filesystem::directory_iterator(spritesAddress))
	{
		if (!textures[i].loadFromFile(entry.path().string()))
			std::cout << "mistakeTextures " << i << " doesn't exist in path: " << entry.path().string() << "\n";

		sprites[i].setTexture(textures[i]);
		sprites[i].setPosition(Positions::CollectBtnClickReports[i][0], Positions::CollectBtnClickReports[i][1]);
		i++;
	}
}

void CollectBtnClickReporter::Draw(sf::RenderWindow& window, int decidedRuleIndex)
{
	window.draw(sprites[decidedRuleIndex]);
}
