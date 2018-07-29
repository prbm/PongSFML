#include "Player.hpp"

Player::Player()
{
    score = scoreInicial = 0;
    vida = vidaInicial = 3;
}

Player::~Player()
{
}

// atualiza o número de vidas da bola
void Player::diminuirVida(int i){
    vida = vida - i;
}

int Player::getVida(){
    return vida;
}

// atualiza o score
void Player::aumentarScore(int i){
    score = score + i;
}

int Player::getScore(){
    return score;
}

void Player::restaurarOriginal(){
   score = scoreInicial;
   vida = vidaInicial;
}

void Player::setNome(std::string n){
    nome = n;
}

std::string Player::getNome(){
    return nome;
}
