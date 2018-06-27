#include "Bastao.h"
#include "Bola.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

enum GameState{
	RUNNING = 1,
	PAUSED
};

int main(int argc, char **argv)
{
	// estado do jogo
	int gameState = RUNNING;
	// define a altura e a largura da janela
	int windowWidth = 800;
	int windowHeight = 600;
	
	// Cria a janela renderizada com os tamanhos definidos acima
	RenderWindow window(VideoMode(windowWidth, windowHeight), "Pong");

	int score = 0;
	int vida = 3;
	
	// cria um bastão
	Bastao bastao( windowWidth/2, windowHeight-20);
	// cria uma bola
	Bola bola( windowWidth/2, 1);

	std::cout << "Criou objetos bola e bastao..." << std::endl;
	
	// Cria objetos para as mensagens do jogo
	Text hud;
	Text gameOver;
	// Fonte a ser usada
	Font font;
	font.loadFromFile("DS-DIGIT.TTF");
	// define a fonte da mensagem, tamanho e cor
	hud.setFont(font);
	hud.setCharacterSize(40);
	hud.setFillColor(sf::Color::White);
	hud.setPosition(windowWidth/2-100, 1);
	// define a mensagem e game over;
	gameOver.setString("Game Over");
	gameOver.setFont(font);
	gameOver.setCharacterSize(150);
	gameOver.setFillColor(sf::Color::Yellow);
	// centraliza o texto na tela
	gameOver.setOrigin(gameOver.getLocalBounds().left + gameOver.getLocalBounds().width/2.0f, 
							gameOver.getLocalBounds().top + gameOver.getLocalBounds().height/2.0f);
	gameOver.setPosition(windowWidth/2.0f,windowHeight/2.0f);

	std::cout << "Carregou as fontes do jogo..." << std::endl;
	
	// entrando no loop do jogo
	while(window.isOpen()){

		// verifica os eventos de tela
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed){
				window.close();
			}
			else if(event.type==Event::KeyPressed){
				if(Keyboard::isKeyPressed(Keyboard::P)){
					if(gameState==RUNNING)
						gameState=PAUSED;
					else
						gameState=RUNNING;
				}
			}

		}// poll event
		
		if(gameState==RUNNING){
			// qual tecla está sendo usada?
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				bastao.moverEsquerda();
			}
			else if(Keyboard::isKeyPressed(Keyboard::Right)){
				bastao.moverDireita();
			}
			else if(Keyboard::isKeyPressed(Keyboard::Escape)){
				window.close();
			}


			// a bola tocou o fundo?
			if(bola.getPosicao().top > windowHeight){
				// reverte a direção da bola
				bola.rebateuFundo();
			
				// remove uma vida
				vida--;
				// restaura a bola à posição inicial
				bola.restaurarPosicaoOriginal();
			}
		
			// a bola tocou o topo?
			if(bola.getPosicao().top < 0){
				bola.rebateuBastaoOuTopo();
			
				// adiciona um ponto ao score
				score++;
				if(score%10==0)
					bola.aumentarVelocidade();
			}
		
			// a bola bateu em um dos lados?
			if(bola.getPosicao().left < 0 || bola.getPosicao().left + 10 > windowWidth){
				bola.rebateuLados();
			}

			// a bola foi atingida pelo bastão?
			if(bola.getPosicao().intersects(bastao.getPosicao())){
				bola.rebateuBastaoOuTopo();
			}
	
			// atualiza as posições na tela
			bola.atualizar();
			bastao.atualizar();
		
			// Atualiza o HUD
			std::stringstream ss;
			ss << "Score: " << score << " Vida: " << vida;
			hud.setString(ss.str());
		
			// limpa o último frame
			window.clear(Color(21, 0, 0, 255));
			window.draw(hud);
		
			// tem menos do que 0 vidas?
			if(vida<=0){
				window.draw(gameOver);
				window.display();
				sf::sleep(sf::milliseconds(3000));
				score = 0;
				vida = 3;
				bola.restaurarOriginal();
				bastao.restaurarOriginal();
				window.draw(bastao.getForma());
				window.draw(bola.getForma());
				window.draw(hud);
				window.display();
			}else{
				window.draw(bastao.getForma());
				window.draw(bola.getForma());
				window.display();
			}
			
		} // if(gameState==RUNNING)

	} // while(window.isOpen())
	
	return 0;
}
