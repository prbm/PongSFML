#include "Bola.h"

Bola::Bola(float inicioX, float inicioY)
{
	posicaoInicial.x = posicaoAtual.x = inicioX;
	posicaoInicial.y = posicaoAtual.y = inicioY;
	
	formaBola.setSize(sf::Vector2f(10, 10));
	formaBola.setPosition(posicaoAtual);
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

void Bola::aumentarVelocidade(){
	velocidadeX = velocidadeX * 1.25;
	velocidadeY = velocidadeY * 1.25;
}


void Bola::rebateuLados(){
	velocidadeX = -velocidadeX;
}

void Bola::rebateuBastaoOuTopo(){
	posicaoAtual.y -= (velocidadeY * 30);
	velocidadeY = -velocidadeY;
}

void Bola::rebateuFundo(){
	posicaoAtual.x = 1;
	posicaoAtual.y = 500;
}

void Bola::atualizar(){
	posicaoAtual.x += velocidadeX;
	posicaoAtual.y += velocidadeY;
	
	formaBola.setPosition(posicaoAtual);
}

void Bola::restaurarOriginal(){
	posicaoAtual = posicaoInicial;
	velocidadeX = velocidadeY = velocidadeIncial;
	atualizar();
}

void Bola::restaurarPosicaoOriginal(){
	posicaoAtual = posicaoInicial;
	atualizar();
}

Bola::~Bola()
{
}

