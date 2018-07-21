#include "Engine.hpp"
#include "SplashScreen.hpp"

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
    bola = new Bola(window.getSize().x/2, 1, window.getSize());
    bastao = new Bastao(window.getSize().x/2, window.getSize().y - 20, window.getSize());
    hud = new HUD(window.getSize());
    hud->setScore(bola->getScore());
    hud->setVida(bola->getVida());
    
    
    // define o status do jogo 
    gameState = GameState::SHOWING_SPLASH ;
}

void Engine::start(){

	while(window.isOpen()){
		// reinicia o relógio e guarda esse valor em dt
//		Time dt = relogio.restart();
		
		// cria uma fração do tempo em milisegundos
//		float dtSegundos = dt.asSeconds();
		
		input();
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

