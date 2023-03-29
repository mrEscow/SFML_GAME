#include "Player.h"
#include "Define.h"
#include "Window.h"


#include <SFML/Graphics.hpp>

Player::Player()
{
    imageREST = RES->getImage("PlayerRest");

    if(!imageREST)
        return;

    imageRUN = RES->getImage("PlayerRun");

    if(!imageRUN)
        return;

    Stage = STAGE::REST;

    switch (Stage){
    case STAGE::REST:
        sprite.setTexture(imageREST->textura);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, imageREST->X, imageREST->Y));
        sprite.setPosition(250, 250);

        break;

    case STAGE::RUN:
        sprite.setTexture(imageRUN->textura);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, imageRUN->X, imageRUN->Y));
        sprite.setPosition(250, 250);

        break;

    default:
        break;
    }
}

void Player::Action()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
        Stage = STAGE::RUN;
        dir = 1;
        sprite.setTexture(imageRUN->textura);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, imageRUN->X, imageRUN->Y));
        sprite.setPosition(250, 250);
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
        Stage = STAGE::RUN;
        dir = -1;
        sprite.setTexture(imageRUN->textura);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(imageRUN->X, 0, -imageRUN->X, imageRUN->Y));
        sprite.setPosition(250, 250);
    }
    else{
        Stage = STAGE::REST;
        sprite.setTexture(imageREST->textura);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, imageREST->X, imageREST->Y));
        sprite.setPosition(250, 250);
    }
}

void Player::Update(const float& time)
{
    float speedAnimation =  0.05f;

    switch (Stage) {

    case STAGE::REST:

        currentFrame += speedAnimation * time ; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
        if (currentFrame > imageREST->frameCount) currentFrame -= imageREST->frameCount; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
        sprite.setTextureRect(sf::IntRect(imageREST->X * int(currentFrame), 0, imageREST->X, imageREST->Y)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
        //sprite.move(-0.1 * playerTime, 0);//происходит само движение персонажа влево


        break;

    case STAGE::RUN:

        if(dir == 1){
            currentFrame += speedAnimation * time ; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (currentFrame > imageRUN->frameCount) currentFrame -= imageRUN->frameCount; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            sprite.setTextureRect(sf::IntRect(imageRUN->X * int(currentFrame), 0, imageRUN->X, imageRUN->Y)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            //sprite.move(-0.1 * playerTime, 0);//происходит само движение персонажа влево
        }

        if(dir == -1){
            currentFrame += speedAnimation * time ; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (currentFrame > imageRUN->frameCount) currentFrame -= imageRUN->frameCount; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            sprite.setTextureRect(sf::IntRect(imageRUN->X * (int(currentFrame) + 1), 0, -imageRUN->X, imageRUN->Y)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            //sprite.move(-0.1 * playerTime, 0);//происходит само движение персонажа влево
        }



        break;

    default:
        break;

    }
}

void Player::Draw()
{
    WND->draw(sprite);
}
