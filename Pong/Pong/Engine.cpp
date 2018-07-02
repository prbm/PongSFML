#include "Engine.hpp"
#include "GameState.h"
//#include "Bola.hpp"

Engine::Engine()
{
	// Define a resolução da tela, e cria uma janela e uma view SFML
	Vector2f resolucao;
//	resolucao.x = VideoMode::getDesktopMode().width;
//	resolucao.y = VideoMode::getDesktopMode().height;
	resolucao.x = 800;
	resolucao.y = 600;
	
	window.create(VideoMode(resolucao.x, resolucao.y), "Pong Game");

    // centraliza a janela no meio da tela
    window.setPosition(Vector2i(VideoMode::getDesktopMode().width/2 - resolucao.x/2, 
                                VideoMode::getDesktopMode().height/2 - resolucao.y/2));
                                
    // cria os objetos que serão usados no jogo
    bola = new Bola(window.getSize().x/2, 1, window.getSize());
    bastao = new Bastao(window.getSize().x/2, window.getSize().y - 20, window.getSize());
    hud = new HUD(window.getSize());
    hud->setScore(bola->getScore());
    hud->setVida(bola->getVida());
    
    
    // define o status do jogo 
    gameState = GameState::state::RUNNING;
}

void Engine::start(){

	while(window.isOpen()){
		// reinicia o relógio e guarda esse valor em dt
//		Time dt = relogio.restart();
		
		// cria uma fração do tempo em milisegundos
//		float dtSegundos = dt.asSeconds();
		
		input();
//		update(dtSegundos);
		draw();
	}
}

void Engine::restart(){
	bastao->restaurarOriginal();
	bola->restaurarOriginal();
//    hud = new HUD(window.getSize());
    hud->setScore(bola->getScore());
    hud->setVida(bola->getVida());
    
    draw();
}

Engine::~Engine()
{
}
