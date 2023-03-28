#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class BackGround : public AGameObject
{
    sf::Texture textura;//создаем объект Texture (текстура)
    sf::Sprite sprite; //создаем объект Sprite(спрайт)
public:
    BackGround();

    virtual void Draw() override;
};

#endif // BACKGROUND_H
