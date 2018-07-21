#include "SplashScreen.hpp"

SplashScreen::SplashScreen()
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::mostrar(RenderWindow & renderWindow){
    // loag Splash Screen image
    Texture image;
    if(image.loadFromFile("images/SplashScreen.png") != true){
        return;
    }
    
    Sprite sprite;
    sprite.setTexture(image);
    
    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
}
