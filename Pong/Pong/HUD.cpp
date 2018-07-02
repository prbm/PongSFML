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

	// define a mensagem e game over;
	gameOver.setString("Game Over");
	gameOver.setFont(font);
	gameOver.setCharacterSize(150);
	gameOver.setFillColor(sf::Color::Yellow);
	// centraliza o texto na tela
	gameOver.setOrigin(gameOver.getLocalBounds().left + gameOver.getLocalBounds().width/2.0f, 
							gameOver.getLocalBounds().top + gameOver.getLocalBounds().height/2.0f);
	gameOver.setPosition(w.x/2.0f,w.y/2.0f-100);

	// define as opções de teclas durante o Game Over
	keyOptions.setString("ENTER -> continue\nESC -> exit");
	keyOptions.setFont(font);
	keyOptions.setCharacterSize(30);
	keyOptions.setFillColor(sf::Color::Yellow);
	keyOptions.setOrigin(keyOptions.getLocalBounds().left + keyOptions.getLocalBounds().width/2.0f,
							keyOptions.getLocalBounds().top + keyOptions.getLocalBounds().height);
	keyOptions.setPosition(w.x/2.0f,w.y/2.0f + gameOver.getLocalBounds().height);
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

Text HUD::getGameOver(){
    return gameOver;
}

Text HUD::getKeyOptions(){
    return keyOptions;
}

HUD::~HUD()
{
}

