#include "AudioManager.h"
#include <iostream>

void AudioManager::LoadAssets()
{
	if (!bgmMusic.openFromFile(bgmPath))
		std::cout << "bgmPath not found\n";
	bgmMusic.setLoop(true);
}

void AudioManager::PlayBgm()
{
	bgmMusic.play();
}
