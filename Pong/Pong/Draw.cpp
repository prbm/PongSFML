#include "Engine.hpp"


void Engine::draw(){
	// limpa o último frame
	window.clear(Color::Black);

    if(gameState == GameState::PLAYING){
        window.draw(hud->getScore());
        window.draw(hud->getVida());
    
        bola->atualizar();
        bastao->atualizar();
        
        window.draw(bola->getForma());
        window.draw(bastao->getForma());

    }
    if(gameState == GameState::LOST){
        window.draw(gameOver->getGameOver());
        window.draw(gameOver->getKeyOptions());
    }

	// mostra a tela completa
	window.display();
}

