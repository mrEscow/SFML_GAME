#ifndef OBLAKO_H
#define OBLAKO_H

#include "GameObject.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Oblako : public AGameObject
{
    sf::Texture textura;//создаем объект Texture (текстура)

    sf::Sprite sprite;

    float currentFrame = 0;

    float runTimer = 250;

    int dir = -1;

public:
    Oblako();

    // AGameObject interface
public:
    //virtual void Action() override;
    virtual void Update(const float& time) override;
    virtual void Draw() override;
};


#endif // OBLAKO_H