#include "GreenWarior.h"

#include "Define.h"
#include "Window.h"

GreenWarior::GreenWarior()
{
    image = RES->getImage("GreenWarriorAttack");

    if(!image)
        return;

    sprite.setTexture(image->textura);
    sprite.setTextureRect(sf::IntRect(0, 0, image->X, image->Y));
    sprite.setPosition(370, 170);
}

void GreenWarior::Update(const float &time)
{
    float speedAnimation =  0.01f;

    currentFrame += speedAnimation * time;

    if (currentFrame > image->frameCount)
        currentFrame -= image->frameCount;

    sprite.setTextureRect(sf::IntRect(image->X * int(currentFrame), 0, image->X, image->Y));
}

void GreenWarior::Draw()
{
    WND->draw(sprite);
}
