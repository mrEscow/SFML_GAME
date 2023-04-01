#ifndef TILE_H
#define TILE_H

#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"


class Tile : public AGameObject
{

public:
    Tile(sf::Vector2f pos, int gid);

};

#endif // TILE_H
