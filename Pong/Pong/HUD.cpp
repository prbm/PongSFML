#include "HUD.hpp"
#include <sstream>

HUD::HUD(Vector2u w)
{
    // carrega a fonte
    font.loadFromFile("DS-DIGIT.TTF");
    
	// define a fonte da mensagem, tamanho e cor
	score.setFont(font);
	score.setCharacterSize(40);
	vida.setString("Score: XXX");
	score.setFillColor(sf::Color::Blue);
	score.setPosition(10, 1);

	// define a HUD de vida
	vida.setFont(font);
	vida.setCharacterSize(40);
	vida.setString("Vida: XX");
	vida.setFillColor(sf::Color::Blue);
	vida.setPosition(w.x - vida.getLocalBounds().width - 10, 1);

}

void HUD::setScore(int value){
    std::stringstream ss;
    ss << "Score: " << value;
    score.setString(ss.str());
}

Text HUD::getScore(){
    return score;
    
}

void HUD::setVida(int value){
    std::stringstream ss;
    ss << "Vida: " << value;
    vida.setString(ss.str());
}

Text HUD::getVida(){
    return vida;
    
}

HUD::~HUD()
{
}

