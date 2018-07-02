#include "Engine.hpp"
#include "GameState.h"
#include <iostream>

//
// Neste arquivo, vamos lidar com as ações do jogador
//
void Engine::input(){
    
    // declara um objeto para leitura de eventos
    Event event;
    while(window.pollEvent(event)){
        if(event.type==Event::Closed){
			window.close();
		}
		else if(event.type==Event::KeyPressed){
            // verifica se o jogo foi pausado
            if(Keyboard::isKeyPressed(Keyboard::P)){
                if(gameState == GameState::state::PAUSED)
                    gameState = GameState::state::RUNNING;
                else
                    gameState = GameState::state::PAUSED;
            }
            // verifica se o jogador quer sair do jogo
            else if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }else if(Keyboard::isKeyPressed(Keyboard::Return)){
                if(gameState == GameState::state::WON || gameState == GameState::state::LOST){
                    gameState = GameState::state::RUNNING;
                    restart();
                }
            }
	
        }
    }// end POLL EVENT
    
    if(gameState == GameState::state::RUNNING){
        // identifica se está movendo o jogador
        if(Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)){
            bastao->moverEsquerda();
        }
        if(Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)){
            bastao->moverDireita();
        }
            
        // tocou o fundo da janela?
        if(bola->getPosicao().top > window.getSize().y){
            bola->rebateuFundo();   // reverte  direção
            bola->diminuirVida(1);  // remove uma vida da bola
            bola->restaurarPosicaoOriginal(); // restaura a bola para a posição original
            hud->setVida(bola->getVida());    // atualiza o vida na HUD
        }
        // tocou o topo?
        if(bola->getPosicao().top < 0){
            bola->rebateuBastaoOuTopo();  // rebateu no bastão ou no topo
            bola->aumentarScore(1);       // adiciona um ponto ao score
            hud->setScore(bola->getScore());   // atualiza o score na HUD
            if(bola->getScore()%5==0)          // aumenta a velocidade da bola a cada cinco pontos
                bola->aumentarVelocidade();
        }
        // a bola bateu em um dos lados?
        if(bola->getPosicao().left < 0 || bola->getPosicao().left + 10 > window.getSize().x){
            bola->rebateuLados();
        }
        // atingiu o bastão?
        if(bola->getPosicao().intersects(bastao->getPosicao())){
            bola->rebateuBastaoOuTopo();
        }
        
        if(bola->getVida()<=0){
            gameState = GameState::state::LOST;
        }
    } // end if(gameState == RUNNING)
}