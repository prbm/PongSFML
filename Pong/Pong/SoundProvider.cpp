#include "SoundProvider.hpp"


SoundProvider::SoundProvider()
{
	_music.setVolume(5);
}

SoundProvider::~SoundProvider()
{
}

void SoundProvider::playEffect(std::string filename) {
	// verifica se a música tem comprimento zero, se for zero
	if (_effect.getDuration() == Time::Zero)
		// carrega um arquivo para a memória
		if (!_effect.openFromFile(filename))
		{
			std::cout << "Erro ao carregar arquivo de áudio: " << filename << std::endl;
			return;
		}

	// se estiver tocando, pára
	if (_effect.getStatus() == Sound::Playing) {
		_effect.stop();
	}

	// música carregada e prestes a ser iniciada
	_effect.play();
}

void SoundProvider::playMusic(std::string filename, bool loop) {
	// verifica se a música tem comprimento zero, se for zero
	if (_musicBuffer.getDuration() == Time::Zero)
		// carrega um arquivo para a memória
		if (!_musicBuffer.loadFromFile(filename))
		{
			std::cout << "Erro ao carregar arquivo de áudio: " << filename << std::endl;
			return;
		}

	// se estiver tocando, pára
	if (_music.getStatus() == Sound::Playing) {
		_music.stop();
	}

	// música carregada e prestes a ser iniciada
	_music.setBuffer(_musicBuffer);
	_music.play();
}

void SoundProvider::stopEffect(){
	if (_effect.getStatus() == Sound::Playing)
		_effect.stop();
}

void SoundProvider::stopMusic(){
	if (_music.getStatus() == Sound::Playing)
		_music.stop();
}

void SoundProvider::stopAudio() {
    stopEffect();
    stopMusic();
}

Music::Status SoundProvider::getEffetStatus() {
	return _effect.getStatus();
}

Sound::Status SoundProvider::getMusicStatus() {
	return _music.getStatus();
}
