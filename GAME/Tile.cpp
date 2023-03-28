#include "Tile.h"

#include "Define.h"
#include "Window.h"


Tile::Tile(sf::Vector2f pos)
{

    sf::Image image; //создаем объект Image (изображение)

    image.loadFromFile("Images/Tiles/Green64x64_10.png");//загружаем в него файл
    textura.loadFromImage(image);//передаем в него объект Image (изображения)

    sprite.setTexture(textura);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
    sprite.setPosition(pos);
}

void Tile::Draw()
{
    WND->draw(sprite);
}
