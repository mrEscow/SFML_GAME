#ifndef OBLAKO_H
#define OBLAKO_H

#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"

class Oblako : public AGameObject
{
    float currentFrame = 0;

    float runTimer = 250;

    int dir = -1;

public:
    Oblako();

    // AGameObject interface
public:
    //virtual void Action() override;
    virtual void Update(const float& time) override;
};


#endif // OBLAKO_H
