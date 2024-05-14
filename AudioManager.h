#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class AudioManager
{
private:
	inline static const std::string bgmPath = "Assets/Audio/bgm.ogg";
	inline static sf::Music bgmMusic;

	//inline static sf::SoundBuffer bgmBuffer;

public:
	static void LoadAssets();
	static void PlayBgm();
};

