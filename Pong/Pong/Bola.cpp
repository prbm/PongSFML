#include "Bola.h"

Bola::Bola(float inicioX, float inicioY)
{
	posicao.x = inicioX;
	posicao.y = inicioY;
	
	formaBola.setSize(sf::Vector2f(10, 10));
	formaBola.setPosition(posicao);
}

FloatRect Bola::getPosicao(){
	return formaBola.getGlobalBounds();
}

RectangleShape Bola::getForma(){
	return formaBola;
}

float Bola::getVelocidadeX(){
	return velocidadeX;
}

void Bola::rebateuLados(){
	velocidadeX = -velocidadeX;
}

void Bola::rebateuBastaoOuTopo(){
	posicao.y -= (velocidadeY * 30);
	velocidadeY = -velocidadeY;
}

void Bola::rebateuFundo(){
	posicao.x = 1;
	posicao.y = 500;
}

void Bola::atualizar(){
	posicao.x += velocidadeX;
	posicao.y += velocidadeY;
	
	formaBola.setPosition(posicao);
}

Bola::~Bola()
{
}

