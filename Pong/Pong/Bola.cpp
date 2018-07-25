#include "Bola.hpp"

Bola::Bola()
{
}

Bola::Bola(RenderWindow & rw)
{
    formaBola.setRadius(5);
    formaBola.setPointCount(30);
    formaBola.setFillColor(Color::White);
	formaBola.setPosition(posicaoAtual);
    
    // define a posição inicial da bola
    wSize = rw.getSize();
	posicaoInicial.x = posicaoAtual.x = wSize.x/2;
	posicaoInicial.y = posicaoAtual.y = formaBola.getRadius() + 10;

    score = scoreInicial = 0;
    vida = vidaInicial = 3;
}

FloatRect Bola::getPosicao(){
	return formaBola.getGlobalBounds();
}

CircleShape Bola::getForma(){
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

