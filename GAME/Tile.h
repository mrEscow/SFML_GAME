#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"


class Tile : public AGameObject
{
    Image* image;

    sf::Sprite sprite; //создаем объект Sprite(спрайт)

public:
    Tile(sf::Vector2f pos, int gid);

    // AGameObject interface
public:
    virtual void Draw() override;
};

#endif // TILE_H
