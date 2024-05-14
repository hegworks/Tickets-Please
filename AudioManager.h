#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class AudioManager
{
private:
	inline static const std::string bgmPath = "Assets/Audio/bgm.ogg";
	inline static sf::Music bgmMusic;

	inline static const std::string correctAnswerPath = "Assets/Audio/CorrectAnswer.wav";
	inline static sf::SoundBuffer correctAnswerBuffer;
	inline static sf::Sound correctAnswerSound;

	inline static const std::string wrongAnswerPath = "Assets/Audio/WrongAnswer.wav";
	inline static sf::SoundBuffer wrongAnswerBuffer;
	inline static sf::Sound wrongAnswerSound;

	inline static const std::string uiClickPath = "Assets/Audio/UiClick.wav";
	inline static sf::SoundBuffer uiClickBuffer;
	inline static sf::Sound uiClickSound;

public:
	static void LoadAssets();
	static void PlayBgm();
	static void PlayCorrectAnswser();
	static void PlayWrongAnswer();
	static void PlayUiClick();
};

