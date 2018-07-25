#ifndef HUD_HPP
#define HUD_HPP

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class HUD
{
private:
    // declara os campos da tela
    Text score;
    Text vida;
    // declara a fonte a ser usada na tela
    Font font;

public:
    HUD(RenderWindow & rw);
    // define as propriedades da HUD
    void setScore(int value);
    Text getScore();
    void setVida(int value);
    Text getVida();

    ~HUD();

};

#endif // HUD_HPP
