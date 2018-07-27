#include "Engine.hpp"
#include "SplashScreen.hpp"
#include "SFML/Audio.hpp"
#include "SoundProvider.hpp"
#include "AudioService.hpp"

Engine::GameState Engine::gameState = GameState::UNINTIALIZED;

Engine::Engine()
{
	// Define a resolução da tela, e cria uma janela e uma view SFML
	Vector2f resolucao;
	resolucao.x = 800;
	resolucao.y = 600;
	
    // cria a tela de modo que não tenha resize
	window.create(VideoMode(resolucao.x, resolucao.y), "Pong Game", Style::Titlebar | Style::Close);
    
     
    window.setPosition(Vector2i(VideoMode::getDesktopMode().width/2 - resolucao.x/2, 
                                VideoMode::getDesktopMode().height/2 - resolucao.y/2));
                                
    // cria os objetos que serão usados no jogo
    bola = new Bola(window);
    bastao = new Bastao(window);
    hud = new HUD(window);
    gameOver = new GameOver(window);
    hud->setScore(bola->getScore());
    hud->setVida(bola->getVida());
    
    
    // define o status do jogo 
    gameState = GameState::SHOWING_SPLASH ;
}

void Engine::start(){

	SoundProvider soundProvider;
	AudioService::registerAudioService(&soundProvider);

	while(window.isOpen()){
		// reinicia o relógio e guarda esse valor em dt
//		Time dt = relogio.restart();
		
		// cria uma fração do tempo em milisegundos
//		float dtSegundos = dt.asSeconds();
		
		input();

		// controla o áudio sendo executado durante o jogo
		switch (gameState)
		{
			case GameState::SHOWING_SPLASH:
				// a fazer, tocar a música de fundo para a splash screen
				break;
			case GameState::WON:
			case GameState::LOST:
				// a fazer, tocar a música de fundo para a splash screen
				break;
			case GameState::PLAYING:
				// interrompe o efeito sonoro se ele estiver ativo
				if (AudioService::getAudio()->getEffetStatus() != sf::Music::Status::Stopped)
					AudioService::getAudio()->stopAudio();

				// ativa a música de fundo e a mantém tocando
				if (AudioService::getAudio()->getMusicStatus() != sf::Sound::Status::Playing)
					AudioService::getAudio()->playMusic("sounds/TheForestAwakes.ogg", true);

				break;
			default:
				break;
		}

//		update(dtSegundos);
//		draw();
	}

}

void Engine::restart(){
	bastao->restaurarOriginal();
	bola->restaurarOriginal();
    hud->setScore(bola->getScore());
    hud->setVida(bola->getVida());
    
    draw();
}

void Engine::mostrarSplashScreen(){
    SplashScreen splashScreen;
    splashScreen.mostrar(window);
    // muda o status do jogo para jogando
    gameState = GameState::PLAYING;
}

Engine::~Engine()
{
}

