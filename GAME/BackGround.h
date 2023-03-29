#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"


class BackGround : public AGameObject
{
    Image* image;
    sf::Sprite sprite; //создаем объект Sprite(спрайт)
public:
    BackGround();

    virtual void Draw() override;
};

#endif // BACKGROUND_H
