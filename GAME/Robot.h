#ifndef ROBOT_H
#define ROBOT_H

#include "GameObject.h"

#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"

class Robot : public AGameObject
{
    float runTimer = 100;

    int dir = -1;

public:
    Robot();

    // AGameObject interface
public:
    //virtual void Action() override;
    virtual void Update(const float& time) override;
};

#endif // ROBOT_H
