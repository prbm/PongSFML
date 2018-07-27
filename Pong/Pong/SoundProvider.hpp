#pragma once
#include "IAudioProvider.h"
#include "SFML/Audio.hpp"

using namespace sf;

class SoundProvider : public IAudioProvider
{
public:
	SoundProvider();
	~SoundProvider();

	void playEffect(std::string filename);
	void playMusic(std::string filename, bool loop);
	void stopEffect();
	void stopMusic();
	void stopAudio();

	Music::Status getEffetStatus();
	Sound::Status getMusicStatus();
private:
	SoundBuffer _musicBuffer;
	Sound		_music;
	Music		_effect;
};

