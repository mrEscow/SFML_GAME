#include "Tile.h"

#include "Define.h"
#include "Window.h"


Tile::Tile(sf::Vector2f pos, int gid)
{
    image = RES->getImage("GreenTiles");

    if(!image)
        return;

    sprite.setTexture(image->textura);
    sprite.setTextureRect(sf::IntRect(image->X * gid, 0, image->X, image->Y));
    sprite.setPosition(pos);
}

void Tile::Draw()
{
    WND->draw(sprite);
}
