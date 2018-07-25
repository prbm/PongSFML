#include "GameOver.hpp"
#include <sstream>

GameOver::GameOver(RenderWindow & rw)
{
    // carrega a fonte
    font.loadFromFile("DS-DIGIT.TTF");

	// define a mensagem e game over;
	gameOver.setString("Game Over");
	gameOver.setFont(font);
	gameOver.setCharacterSize(150);
	gameOver.setFillColor(sf::Color::Yellow);
	// centraliza o texto na tela
	gameOver.setOrigin(gameOver.getLocalBounds().left + gameOver.getLocalBounds().width/2.0f, 
							gameOver.getLocalBounds().top + gameOver.getLocalBounds().height/2.0f);
	gameOver.setPosition(rw.getSize().x/2.0f,rw.getSize().y/2.0f-100);

	// define as opções de teclas durante o Game Over
	keyOptions.setString("ENTER -> continue\nESC -> exit");
	keyOptions.setFont(font);
	keyOptions.setCharacterSize(30);
	keyOptions.setFillColor(sf::Color::Yellow);
	keyOptions.setOrigin(keyOptions.getLocalBounds().left + keyOptions.getLocalBounds().width/2.0f,
							keyOptions.getLocalBounds().top + keyOptions.getLocalBounds().height);
	keyOptions.setPosition(rw.getSize().x/2.0f,
                                    rw.getSize().y/2.0f + gameOver.getLocalBounds().height);    
}

Text GameOver::getGameOver(){
    return gameOver;
}

Text GameOver::getKeyOptions(){
    return keyOptions;
}

GameOver::~GameOver()
{
}

