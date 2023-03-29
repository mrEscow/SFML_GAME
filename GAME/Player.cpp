#include "Player.h"
#include "Define.h"
#include "Window.h"


#include <SFML/Graphics.hpp>

Player::Player()
{
    sf::Image image; //создаем объект Image (изображение)

    image.loadFromFile("Images/Player/Rest/spritesheet.png");//загружаем в него файл
    texturaREST.loadFromImage(image);//передаем в него объект Image (изображения)

    image.loadFromFile("Images/Player/Run/spritesheet.png");//загружаем в него файл
    texturaRUN.loadFromImage(image);//передаем в него объект Image (изображения)



    Stage = STAGE::REST;

    switch (Stage){
    case STAGE::REST:
        sprite.setTexture(texturaREST);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, 65, 98));
        sprite.setPosition(250, 250);

        break;

    case STAGE::RUN:
        sprite.setTexture(texturaRUN);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, 58, 100));
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
        sprite.setTexture(texturaRUN);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, 58, 100));
        sprite.setPosition(250, 250);
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
        Stage = STAGE::RUN;
        dir = -1;
        sprite.setTexture(texturaRUN);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(58, 0, -58, 100));
        sprite.setPosition(250, 250);
    }
    else{
        Stage = STAGE::REST;
        sprite.setTexture(texturaREST);//передаём в него объект Texture (текстуры)
        sprite.setTextureRect(sf::IntRect(0, 0, 65, 98));
        sprite.setPosition(250, 250);
    }
}

void Player::Update(const float& time)
{
    float speedAnimation =  0.05f;

    switch (Stage) {

    case STAGE::REST:

        currentFrame += speedAnimation * time ; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
        if (currentFrame > 17) currentFrame -= 17; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
        sprite.setTextureRect(sf::IntRect(65 * int(currentFrame), 0, 65, 98)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
        //sprite.move(-0.1 * playerTime, 0);//происходит само движение персонажа влево


        break;

    case STAGE::RUN:

        if(dir == 1){
            currentFrame += speedAnimation * time ; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (currentFrame > 26) currentFrame -= 26; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            sprite.setTextureRect(sf::IntRect(58 * int(currentFrame), 0, 58, 100)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
            //sprite.move(-0.1 * playerTime, 0);//происходит само движение персонажа влево
        }

        if(dir == -1){
            currentFrame += speedAnimation * time ; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
            if (currentFrame > 25) currentFrame -= 25; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
            sprite.setTextureRect(sf::IntRect(58 * int(currentFrame) + 1, 0, -58, 100)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
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
