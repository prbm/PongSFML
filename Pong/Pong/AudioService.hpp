#pragma once

#include "IAudioProvider.h"

class AudioService
{
public:
	AudioService();
	~AudioService();

	static IAudioProvider * getAudio() { return _audioService; } const

	static void registerAudioService(IAudioProvider * provider) {
		_audioService = provider;
	}

private:
	static IAudioProvider * _audioService;
};

