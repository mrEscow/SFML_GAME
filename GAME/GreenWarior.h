#ifndef GREENWARIOR_H
#define GREENWARIOR_H

#include "GameObject.h"

#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"


class GreenWarior : public AGameObject
{
    float currentFrame = 0;

public:
    GreenWarior();

    // AGameObject interface
public:
    //virtual void Action() override;
    virtual void Update(const float& time) override;
};

#endif // GREENWARIOR_H
