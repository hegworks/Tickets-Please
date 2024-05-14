#include "AudioManager.h"
#include <iostream>

void AudioManager::LoadAssets()
{
	// bgm
	if (!bgmMusic.openFromFile(bgmPath))
		std::cout << "bgmPath not found\n";
	bgmMusic.setLoop(true);

	// CorrectAnswer
	if (!correctAnswerBuffer.loadFromFile(correctAnswerPath))
		std::cout << "correctAnswerPath not found\n";
	correctAnswerSound.setBuffer(correctAnswerBuffer);

	// WrongAnswer
	if (!wrongAnswerBuffer.loadFromFile(wrongAnswerPath))
		std::cout << "wrongAnswerPath not found\n";
	wrongAnswerSound.setBuffer(wrongAnswerBuffer);

	// uiClick
	if (!uiClickBuffer.loadFromFile(uiClickPath))
		std::cout << "uiClickPath not found\n";
	uiClickSound.setBuffer(uiClickBuffer);

}

void AudioManager::PlayBgm()
{
	bgmMusic.play();
}

void AudioManager::PlayCorrectAnswser()
{
	correctAnswerSound.play();
}

void AudioManager::PlayWrongAnswer()
{
	wrongAnswerSound.play();
}

void AudioManager::PlayUiClick()
{
	uiClickSound.play();
}
