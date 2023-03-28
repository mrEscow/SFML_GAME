#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"


class Tile : public AGameObject
{
    sf::Texture textura;//создаем объект Texture (текстура)
    sf::Sprite sprite; //создаем объект Sprite(спрайт)
public:
    Tile(sf::Vector2f pos);

    // AGameObject interface
public:
    virtual void Draw() override;
};

#endif // TILE_H
