#ifndef ROBOT_H
#define ROBOT_H

#include "GameObject.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Robot : public AGameObject
{

    sf::Texture textura;//создаем объект Texture (текстура)

    sf::Sprite sprite;

    float currentFrame = 0;

    float runTimer = 100;

    int dir = -1;

public:
    Robot();

    // AGameObject interface
public:
    //virtual void Action() override;
    virtual void Update(const float& time) override;
    virtual void Draw() override;
};

#endif // ROBOT_H
