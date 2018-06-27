#include <SFML/Graphics.hpp>

using namespace sf;

class Bastao{
private:
	// posicao do bastao
	Vector2f posicaoInicial;
	Vector2f posicao;
	// um objeto retangulo, a forma do bastao
	RectangleShape formaBastao;
	// velocidade do bastao
	float velocidadeBastao = 0.3f;
		
public:
	// declaracao do construtor
	Bastao(float inicioX, float inicioY);
	// informa posicao da figura
	FloatRect getPosicao();
	// informa a forma da figura
	RectangleShape getForma();
	// funcoes de movimento
	void moverEsquerda();
	void moverDireita();
	void atualizar();
	// restaura estado original
	void restaurarOriginal();
};
