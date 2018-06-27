#ifndef BOLA_H
#define BOLA_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Bola
{
private:
	// define as constantes
	float const velocidadeIncial = 0.3f;
	// posicao da bola
	Vector2f posicaoInicial;
	Vector2f posicaoAtual;
	// forma de bola
	RectangleShape formaBola;
	// velocidades da bola
	float velocidadeX = velocidadeIncial;
	float velocidadeY = velocidadeIncial;
	
public:
	// definicao do construtor
	Bola(float inicioX, float inicioY);
	
	// informa posicao do retângulo
	FloatRect getPosicao();
	
	// informa a forma da figura
	RectangleShape getForma();
	
	// aumenta a velocidade da bola
	void aumentarVelocidade();

	// lê a velocidade X
	float getVelocidadeX();
	
	// bateu nos lados?
	void rebateuLados();
	
	// bateu em cima ou em baixo?
	void rebateuBastaoOuTopo();
	
	// bateu embaixo?
	void rebateuFundo();
	
	// atualizar
	void atualizar();
	
	// restaurar ao estado original
	void restaurarOriginal();
	
	~Bola();

};

#endif // BOLA_H
