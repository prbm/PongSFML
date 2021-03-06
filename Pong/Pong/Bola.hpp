#ifndef BOLA_HPP
#define BOLA_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Bola
{
private:
	// define as constantes
	float const velocidadeIncial = 0.3f; // velocidade inicial
    Vector2u wSize; // tamanho da tela
	// posicao da bola
	Vector2f posicaoInicial;
	Vector2f posicaoAtual;
	// forma de bola
	CircleShape formaBola;
	// velocidades da bola
	float velocidadeX = velocidadeIncial;
	float velocidadeY = velocidadeIncial;
    // define as informações da Sprite
	sf::Texture _image;
	std::string _filename;    
    
protected:
    std::string getSpriteFileName();
    void setSpriteFileName();
	
public:
    Bola();

	// definicao do construtor
    Bola(RenderWindow & rw);
	
	// informa posicao do retângulo
	FloatRect getPosicao();
	
	// informa a forma da figura
	CircleShape getForma();
	
	// aumenta a velocidade da bola
	void aumentarVelocidade();

	// lê a velocidade X
	float getVelocidadeX();
	
	// bateu nos lados?
	void rebateuLados();
	
	// bateu em cima ou em baixo?
	void rebateuBastaoOuTopo();
	
	// bateu embaixo?
	void rebateuFundo();
	
	// atualizar
	void atualizar();
	
	// restaurar ao estado original
	void restaurarOriginal();
	void restaurarPosicaoOriginal();
    
    ~Bola();

};

#endif // BOLA_HPP
