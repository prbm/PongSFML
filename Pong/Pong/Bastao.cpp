#include "Bastao.hpp"
#include <iostream>

Bastao::Bastao()
{
}

Bastao::Bastao(RenderWindow & rw) 
{
    setSpriteFileName(); // define o nome da imagem
    if(_image.loadFromFile(_filename)!=true){
        std::cout << "Erro ao carregar arquivo " << _filename << std::endl;
        return;
    }
    else
    {
        // define o contorno da imagem como sendo suave
        _image.setSmooth(true);
    }
    formaBastao.setTexture(&_image);

    // define o tamanho do bastão
    formaBastao.setSize(sf::Vector2f(50,10));

    // define a posição inicial do bastão
    wSize = rw.getSize();
    posicao.x = wSize.x/2;
    if((formaBastao.getSize().y * 1.5 ) > 15){
        posicao.y = wSize.y - (formaBastao.getSize().y * 1.5 ); 
    }
    else{
        posicao.y = wSize.y - 15; 
    }
        
	formaBastao.setPosition(posicao);
    posicaoInicial = posicao;
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

std::string Bastao::getSpriteFileName(){
    return _filename;
}

void Bastao::setSpriteFileName(){
    // tenta carregar a imagem 
    _filename = "images/paddle.png";    
}

Bastao::~Bastao()
{
}

