#ifndef BOLA_H
#define BOLA_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Bola
{
private:
	// posicao da bola
	Vector2f posicao;
	// forma de bola
	RectangleShape formaBola;
	// velocidades da bola
	float velocidadeX = 0.3f;
	float velocidadeY = 0.3f;
	
public:
	// definicao do construtor
	Bola(float inicioX, float inicioY);
	
	// informa posicao do retângulo
	FloatRect getPosicao();
	
	// informa a forma da figura
	RectangleShape getForma();
	
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
	
	~Bola();

};

#endif // BOLA_H
