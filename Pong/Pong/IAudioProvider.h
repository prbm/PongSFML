#pragma once
#include "SFML/Audio.hpp"
#include <iostream>

using namespace sf;

class IAudioProvider {
public:
	virtual ~IAudioProvider() {}
	virtual void playEffect(std::string filename) = 0;
	virtual void playMusic(std::string filename, bool loop) = 0;
	virtual void stopEffect() = 0;
	virtual void stopMusic() = 0;
	virtual void stopAudio() = 0;

	virtual Music::Status getEffetStatus() = 0;
	virtual Sound::Status getMusicStatus() = 0;
};
