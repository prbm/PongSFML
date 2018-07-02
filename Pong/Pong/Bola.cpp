#include "Bola.hpp"

Bola::Bola()
{
}

Bola::Bola(float inicioX, float inicioY, Vector2u w)
{
	posicaoInicial.x = posicaoAtual.x = inicioX;
	posicaoInicial.y = posicaoAtual.y = inicioY;
	
	formaBola.setSize(sf::Vector2f(10, 10));
	formaBola.setPosition(posicaoAtual);
    
    wSize = w;
    score = scoreInicial = 0;
    vida = vidaInicial = 3;
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
	velocidadeX = velocidadeX * 1.1;
	velocidadeY = velocidadeY * 1.1;
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
    score = scoreInicial;
    vida = vidaInicial;
	atualizar();
}

void Bola::restaurarPosicaoOriginal(){
	posicaoAtual = posicaoInicial;
	atualizar();
}

// atualiza o número de vidas da bola
void Bola::diminuirVida(int i){
    vida = vida - i;
}

int Bola::getVida(){
    return vida;
}

// atualiza o score
void Bola::aumentarScore(int i){
    score = score + i;
}

int Bola::getScore(){
    return score;
}


Bola::~Bola()
{
}

