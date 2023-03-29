#include "BackGround.h"
#include "Define.h"
#include "Window.h"

BackGround::BackGround()
{
    image = RES->getImage("BackGround#1");

    if(!image)
        return;

    sprite.setTexture(image->textura);//передаём в него объект Texture (текстуры)
    //sprite.setPosition(50, 25);//задаем начальные координаты появления спрайта

    sf::Vector2f targetSize(WND->getSize()); //целевой размер

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width,
        targetSize.y / sprite.getLocalBounds().height);
}

void BackGround::Draw(){
   WND->draw(sprite);
}
