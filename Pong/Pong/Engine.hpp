#ifndef ENGINE_HPP
#define ENGINE_HPP

#pragma once

#include <SFML/Graphics.hpp>
#include "Bola.hpp"
#include "Bastao.hpp"
#include "HUD.hpp"

using namespace sf;

class Engine
{
private:
	// define uma tela a ser renderizada
	RenderWindow window;
	// cria as funções para uso interno
	void input();   // controle de entradas do jogador
	void update(float dtSegundos);  // atualizar os personagens
	void draw();    // desenha a tela
    void mostrarSplashScreen();    // declara o método que exibe a tela de Splash Screen
    
    Bola * bola;
    Bastao * bastao;
    HUD * hud;
    
public:
    // define os estados dos jogos
    enum GameState{
        PLAYING = 1,
        PAUSED,
        WON,
        LOST,
        UNINTIALIZED, 
        SHOWING_SPLASH,
        SHOWING_MENU,
        EXITING        
    };
    
    // declara variável para armazenar o estado do jogo
    static GameState gameState;

    // declara o método que inicia o jogo
    void start();
    // declara o método que reinicia o jogo
    void restart();

    
    Engine();
    ~Engine();

};

#endif // ENGINE_HPP
