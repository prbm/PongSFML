#ifndef GAMEOVER_HPP
#define GAMEOVER_HPP

#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class GameOver
{
public:
    GameOver(Vector2u w);
    ~GameOver();

    Text getGameOver();
    Text getKeyOptions();
    

private:
    Text gameOver;
    Text keyOptions;
    // declara a fonte a ser usada na tela
    Font font;
};

#endif // GAMEOVER_HPP
