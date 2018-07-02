#ifndef ENGINE_HPP
#define ENGINE_HPP
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
    Bola * bola;
    Bastao * bastao;
    HUD * hud;
    int gameState;
    
public:
    // declara o método que inicia o jogo
    void start();
    // declara o método que reinicia o jogo
    void restart();
    
    Engine();
    ~Engine();

};

#endif // ENGINE_HPP
