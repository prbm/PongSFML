#include "Engine.hpp"
#include <iostream>
#include <thread>
#include <chrono>

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
                if(gameState == GameState::PAUSED)
                    gameState = GameState::PLAYING;
                else
                    gameState = GameState::PAUSED;
            }
            // verifica se o jogador quer sair do jogo
            else if(Keyboard::isKeyPressed(Keyboard::Escape)){
                window.close();
            }else if(Keyboard::isKeyPressed(Keyboard::Return)){
                if(gameState == GameState::SHOWING_GAME_OVER){
                    gameState = GameState::PLAYING;
                    restart();
                }
            }
	
        }
    }// end POLL EVENT
    
    if(gameState == GameState::SHOWING_SPLASH){
        mostrarSplashScreen();
        // show Splash Screen for 2.5 seconds
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        //break;        
    }
    else if(gameState == GameState::PLAYING){
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
            player->diminuirVida(1);  // remove uma vida da bola
            bola->restaurarPosicaoOriginal(); // restaura a bola para a posição original
            hud->setVida(player->getVida());    // atualiza o vida na HUD
        }
        // tocou o topo?
        if(bola->getPosicao().top < 0){
            bola->rebateuBastaoOuTopo();  // rebateu no bastão ou no topo
            player->aumentarScore(1);       // adiciona um ponto ao score
            hud->setScore(player->getScore());   // atualiza o score na HUD
            if(player->getScore()%5==0)          // aumenta a velocidade da bola a cada cinco pontos
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
        
        if(player->getVida()<=0){
            gameState = GameState::SHOWING_GAME_OVER;
			// interrompe o efeito sonoro se ele estiver ativo
			if (AudioService::getAudio()->getEffetStatus() != sf::Music::Status::Playing){
                AudioService::getAudio()->stopMusic();
                AudioService::getAudio()->playEffect("sounds/boom.wav");            
            }
        }
        
        // atualiza a tela
        draw();
    } // end if(gameState == PLAYING)
}
