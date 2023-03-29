#ifndef GREENWARIOR_H
#define GREENWARIOR_H

#include "GameObject.h"

#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"


class GreenWarior : public AGameObject
{
    Image* image;

    sf::Sprite sprite;

    float currentFrame = 0;

public:
    GreenWarior();

    // AGameObject interface
public:
    //virtual void Action() override;
    virtual void Update(const float& time) override;
    virtual void Draw() override;
};

#endif // GREENWARIOR_H
