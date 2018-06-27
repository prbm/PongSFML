#include "Bastao.h"

Bastao::Bastao(float inicioX, float inicioY)
{	posicao.x = inicioX;
	posicao.y = inicioY;
	
	posicaoInicial = posicao;

	formaBastao.setSize(sf::Vector2f(50,5));
	formaBastao.setPosition(posicao);
}

FloatRect Bastao::getPosicao(){
	return formaBastao.getGlobalBounds();
}

RectangleShape Bastao::getForma(){
	return formaBastao;
}

void Bastao::moverEsquerda(){
	posicao.x -= velocidadeBastao;
}

void Bastao::moverDireita(){
	posicao.x += velocidadeBastao;
}

void Bastao::atualizar(){
	formaBastao.setPosition(posicao);
}

void Bastao::restaurarOriginal(){
	posicao = posicaoInicial;
	atualizar();
}

