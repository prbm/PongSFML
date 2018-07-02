#include "Bastao.hpp"

Bastao::Bastao()
{
}

Bastao::Bastao(float inicioX, float inicioY, Vector2u w)
{	
    posicao.x = inicioX;
	posicao.y = inicioY;
	
	posicaoInicial = posicao;

	formaBastao.setSize(sf::Vector2f(50,5));
	formaBastao.setPosition(posicao);
    
    wSize = w;
}

FloatRect Bastao::getPosicao(){
	return formaBastao.getGlobalBounds();
}

RectangleShape Bastao::getForma(){
	return formaBastao;
}

void Bastao::moverEsquerda(){
    if(posicao.x > 0)
        posicao.x -= velocidadeBastao;
}

void Bastao::moverDireita(){
    if(posicao.x < (wSize.x - getForma().getSize().x))
        posicao.x += velocidadeBastao;
}

void Bastao::atualizar(){
	formaBastao.setPosition(posicao);
}

void Bastao::restaurarOriginal(){
	posicao = posicaoInicial;
	atualizar();
}

Bastao::~Bastao()
{
}

