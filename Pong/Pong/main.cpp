#include "Bastao.h"
#include "Bola.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char **argv)
{
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
	
	// Cria um objeto para mensagem de texto
	Text hud;
	// Fonte a ser usada
	Font font;
	font.loadFromFile("DS-DIGIT.TTF");
	// define a fonte da mensagem, tamanho e cor
	hud.setFont(font);
	hud.setCharacterSize(34);
	hud.setFillColor(sf::Color::White);

	std::cout << "Carregou as fontes do jogo..." << std::endl;
	
	// entrando no loop do jogo
	while(window.isOpen()){

		// verifica os eventos de tela
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed)
				window.close();
		}
		
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
			
			// tem menos de zero vidas?
			if(vida < 1){
				score = 0;
				vida = 3;
			}
		}
		
		// a bola tocou o topo?
		if(bola.getPosicao().top < 0){
			bola.rebateuBastaoOuTopo();
			
			// adiciona um ponto ao score
			score++;
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
		
		// atualizou as posições na tela
		std::cout << "Atualizou bola e bastao..." << std::endl;
		
		// Atualiza o HUD
		std::stringstream ss;
		ss << "Score: " << score << " Vida: " << vida;
		hud.setString(ss.str());
		
		// limpa o último frame
		window.clear(Color(26, 128, 128, 255));
		window.draw(bastao.getForma());
		window.draw(bola.getForma());
		window.draw(hud);
		
		window.display();
	}
	
	return 0;
}
