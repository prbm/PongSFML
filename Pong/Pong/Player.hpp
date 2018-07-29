#ifndef PLAYER_HPP
#define PLAYER_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Player
{
public:
    Player();
    ~Player();
    // atualiza o número de vidas do jogador
    void diminuirVida(int i);
    int getVida();
    // atualiza o score
    void aumentarScore(int i);
    int getScore();
	// restaurar ao estado original
	void restaurarOriginal();
    // atribui/recupera nome do jogador
    void setNome(std::string n);
    std::string getNome();
    
private:
    // score do jogador
    int scoreInicial;
    int score;
    // pontuação do jogador
    int vidaInicial;
    int vida;
    // nome do jogador
    string nome;
};

#endif // PLAYER_HPP
