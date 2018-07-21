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
    Text gameOver;
    Text keyOptions;
    // declara a fonte a ser usada na tela
    Font font;

public:
    HUD(Vector2u w);
    // define as propriedades da HUD
    void setScore(int value);
    Text getScore();
    void setVida(int value);
    Text getVida();
    Text getGameOver();
    Text getKeyOptions();

    ~HUD();

};

#endif // HUD_HPP
