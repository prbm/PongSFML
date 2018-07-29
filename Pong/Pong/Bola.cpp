#include "Bola.hpp"

Bola::Bola()
{
}

Bola::Bola(RenderWindow & rw)
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

    formaBola.setRadius(5);
	formaBola.setPosition(posicaoAtual);
    formaBola.setTexture(&_image, false);
    
    // define a posição inicial da bola
    wSize = rw.getSize();
	posicaoInicial.x = posicaoAtual.x = wSize.x/2;
	posicaoInicial.y = posicaoAtual.y = formaBola.getRadius() + 10;

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
	atualizar();
}

void Bola::restaurarPosicaoOriginal(){
	posicaoAtual = posicaoInicial;
	atualizar();
}

std::string Bola::getSpriteFileName()
{
    return _filename;    
}

void Bola::setSpriteFileName()
{
    // tenta carregar a imagem 
    _filename = "images/ball.png";    
}


Bola::~Bola()
{
}

