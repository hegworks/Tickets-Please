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

//void CollectBtnClickReporter::Initialize(sf::RenderWindow& renderWindow)
//{
//	window = &renderWindow;
//}

void CollectBtnClickReporter::Show(int index)
{
	reportIndex = index;
	canShow = true;
	/*if (canShow)
	{
		window->draw(sprites[decidedRuleIndex]);
	}*/
}

void CollectBtnClickReporter::Draw(sf::RenderWindow& renderWindow)
{
	if (canShow)
	{
		renderWindow.draw(sprites[reportIndex]);
	}
}

void CollectBtnClickReporter::Hide()
{
	canShow = false;
}
