#include "Oblako.h"

#include "Define.h"
#include "Window.h"


Oblako::Oblako()
{
    image = RES->getImage("Oblako");

    if(!image)
        return;

    sprite.setTexture(image->textura);

    sprite.setPosition(1500, 100);
}

void Oblako::Update(const float &time)
{
    float speedAnimation =  0.01f;
    currentFrame += speedAnimation * time;

    runTimer -= speedAnimation * time;
    if(runTimer < 0) runTimer = 250;
    runTimer > 125 ? dir = -1 : dir = 1;

    sprite.move(dir * 2, 0);//происходит само движение персонажа влево
}

void Oblako::Draw()
{
    WND->draw(sprite);
}
