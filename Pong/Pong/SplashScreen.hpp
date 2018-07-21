#ifndef SPLASHSCREEN_HPP
#define SPLASHSCREEN_HPP

#pragma once

#include "SFML/Graphics.hpp"

using namespace sf;

class SplashScreen
{
public:
    SplashScreen();
    ~SplashScreen();

    static void mostrar(RenderWindow & renderWindow);
};

#endif // SPLASHSCREEN_HPP
