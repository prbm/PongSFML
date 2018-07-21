#include "Engine.hpp"


void Engine::draw(){
	// limpa o último frame
	window.clear(Color::Black);

    window.draw(hud->getScore());
    window.draw(hud->getVida());
    
    if(gameState == GameState::PLAYING){
        bola->atualizar();
        bastao->atualizar();
    }
    if(gameState == GameState::LOST){
        window.draw(hud->getGameOver());
        window.draw(hud->getKeyOptions());
    }

    window.draw(bola->getForma());
    window.draw(bastao->getForma());

	// mostra a tela completa
	window.display();
}

