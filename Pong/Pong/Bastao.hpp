#ifndef BASTAO_HPP
#define BASTAO_HPP

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Bastao
{
private:
	// posicao do bastao
	Vector2f posicaoInicial;
	Vector2f posicao;
	// um objeto retangulo, a forma do bastao
	RectangleShape formaBastao;
	// velocidade do bastao
	float velocidadeBastao = 0.3f;
    // define o tamanho da tela
    Vector2u wSize;
    // define as informações da Sprite
	sf::Texture _image;
	std::string _filename;

protected:
    // informa a imagem da Sprite
    std::string getSpriteFileName();
    void setSpriteFileName();

public:
	// declaracao do construtor
	Bastao(RenderWindow & rw);
	// informa posicao da figura
	FloatRect getPosicao();
	// informa a forma da figura
	RectangleShape getForma();
	// funcoes de movimento
	void moverEsquerda();
	void moverDireita();
	void atualizar();
	// restaura estado original
	void restaurarOriginal();

    Bastao();
    ~Bastao();

};

#endif // BASTAO_HPP
