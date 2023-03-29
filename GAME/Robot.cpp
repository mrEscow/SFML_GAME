#include "Robot.h"

#include "Define.h"
#include "Window.h"

Robot::Robot()
{
    sf::Image image;
    image.loadFromFile("Images/Enemy/Robot.png");

    textura.loadFromImage(image);

    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 137, 136));
    sprite.setPosition(1000, 480);
}

void Robot::Update(const float &time)
{
    float speedAnimation =  0.01f;

    currentFrame += speedAnimation * time;

    if (currentFrame > 16)
        currentFrame -= 16;

    sprite.setTextureRect(sf::IntRect(137 * int(currentFrame), 0, 137, 136));

    runTimer -= speedAnimation * time;
    if(runTimer < 0) runTimer = 100;
    runTimer > 50 ? dir = -1 : dir = 1;

    sprite.move(dir * 2, 0);//происходит само движение персонажа влево
}

void Robot::Draw()
{
    WND->draw(sprite);
}
