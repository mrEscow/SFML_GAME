#include "BackGround.h"
#include "Define.h"
#include "Window.h"

BackGround::BackGround() : AGameObject("BackGround#1")
{
    sf::Vector2f targetSize(WND->getSize()); //целевой размер

    sprite.setScale(
        targetSize.x / sprite.getLocalBounds().width,
        targetSize.y / sprite.getLocalBounds().height);


}

