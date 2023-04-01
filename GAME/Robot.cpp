#include "Robot.h"

#include "Define.h"
#include "Window.h"

Robot::Robot(): AGameObject("RobotRides",1000, 480)
{
    sprite.setTexture(imageData->textura);
    sprite.setTextureRect(sf::IntRect(0, 0, imageData->W, imageData->H));
    sprite.setPosition(1000, 480);
}

void Robot::Update(const float &time)
{
    float speedAnimation =  0.01f;

    currentFrame += speedAnimation * time;

    if (currentFrame > imageData->frameCount)
        currentFrame -=  imageData->frameCount;

    sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame), 0,  imageData->W, imageData->H));

    runTimer -= speedAnimation * time;
    if(runTimer < 0) runTimer = 100;
    runTimer > 50 ? dir = -1 : dir = 1;

    sprite.move(dir * 2, 0);//происходит само движение персонажа влево
}


