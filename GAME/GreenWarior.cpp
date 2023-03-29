#include "GreenWarior.h"

#include "Define.h"
#include "Window.h"

GreenWarior::GreenWarior()
{
    sf::Image image;
    image.loadFromFile("Images/Enemy/GreenWariorFair.png");

    textura.loadFromImage(image);

    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 186, 189));
    sprite.setPosition(370, 170);
}

void GreenWarior::Update(const float &time)
{
    float speedAnimation =  0.01f;

    currentFrame += speedAnimation * time;

    if (currentFrame > 24)
        currentFrame -= 24;

    sprite.setTextureRect(sf::IntRect(186 * int(currentFrame), 0, 186, 189));
}

void GreenWarior::Draw()
{
    WND->draw(sprite);
}
