#include "BackGround.h"
#include "Define.h"
#include "Window.h"

BackGround::BackGround(){
    sf::Image image; //создаем объект Image (изображение)
    image.loadFromFile("Images/BackGround.jpg");//загружаем в него файл
    //image.createMaskFromColor(sf::Color(255, 255, 255)); // убирает лишний цвет


    textura.loadFromImage(image);//передаем в него объект Image (изображения)

    sprite.setTexture(textura);//передаём в него объект Texture (текстуры)
    //sprite.setPosition(50, 25);//задаем начальные координаты появления спрайта

    sf::Vector2f targetSize(WND->getSize()); //целевой размер

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width,
        targetSize.y / sprite.getLocalBounds().height);
}

void BackGround::Draw(){
   WND->draw(sprite);
}
