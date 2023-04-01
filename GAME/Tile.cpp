#include "Tile.h"

#include "Define.h"
#include "Window.h"


Tile::Tile(sf::Vector2f pos, int gid) : AGameObject("GreenTiles", pos.x, pos.y)
{
    sprite.setTexture(imageData->textura);
    sprite.setTextureRect(sf::IntRect(imageData->W * gid, 0, imageData->W, imageData->H));
    sprite.setPosition(pos);
}
