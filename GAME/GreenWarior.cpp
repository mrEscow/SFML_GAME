#include "GreenWarior.h"

#include "Define.h"
#include "Window.h"

GreenWarior::GreenWarior(): AGameObject("GreenWarriorAttack", 370, 170)
{
    sprite.setTexture(imageData->textura);
    sprite.setTextureRect(sf::IntRect(0, 0, imageData->W, imageData->H));

    sprite.setPosition(1000, 480);
}

void GreenWarior::Update(const float &time)
{
    float speedAnimation =  0.01f;

    currentFrame += speedAnimation * time;

    if (currentFrame > imageData->frameCount)
        currentFrame -= imageData->frameCount;

    sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame), 0, imageData->W, imageData->H));
}
