#include "Player.h"
#include "Define.h"
#include "Window.h"


#include <SFML/Graphics.hpp>

Player::Player(std::vector <MapObject> mapObject) : AGameObject("PlayerStayDrop", 250, 250)
{
    obj = mapObject;

    Stage = STAGE::STAY_DROP;

    sprite.setPosition(250, 250);

    //onGround = false;

    speed = 0.4;
}

void Player::Action()
{
    if(Stage == STAGE::STAY){

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) && (onGround)) {
            Stage = STAGE::STAY_JUMP;
            setImageDate("PlayerStayJump");
            dy = -0.9;
            onGround = false;
            std::cout << "STAGE: " << "STAY_JUMP" << std::endl;
            return;
        }

        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) && (onGround)) {
            Stage = STAGE::STAY_SITTING;
            setImageDate("PlayerStaySitting");
            std::cout << "STAGE: " << "STAY_SITTING" << std::endl;
            isStaySitting = true;
            return;
        }

    }

    if(Stage == STAGE::STAY_JUMP){
        if(dy >= 0){
            Stage = STAGE::STAY_DROP;
            setImageDate("PlayerStayDrop");
            std::cout << "STAGE: " << "STAY_DROP" << std::endl;
            return;
        }
    }

    if(Stage == STAGE::STAY_SITTING){
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S))) && (onGround)) {
            std::cout << "STAGE: " << "STAY_SITTING" << std::endl;
            isStaySitting = true;
            return;
        }
        else{
            Stage = STAGE::STAY;
            setImageDate("PlayerStay");
            std::cout << "STAGE: " << "STAY" << std::endl;
        }
    }


    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
        Stage = STAGE::RUN_RIGHT;
        setImageDate("PlayerRun");
        std::cout << "STAGE: " << "RUN_RIGHT" << std::endl;
        return;
    }


    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
        Stage = STAGE::RUN_LEFT;
        setImageDate("PlayerRun");
        std::cout << "STAGE: " << "RUN_LEFT" << std::endl;
        return;
    }

    if(onGround){
        Stage = STAGE::STAY;
        setImageDate("PlayerStay");
        std::cout << "STAGE: " << "STAY" << std::endl;
        return;
    }

}

void Player::Update(const float& time)
{

    currentFrame += speedAnimation * time ;

    switch (Stage) {

    case STAGE::STAY:
        dx = 0;
        if (currentFrame > imageData->frameCount) currentFrame -= imageData->frameCount;
        std::cout << "STAGE: " << "STAY" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::STAY_JUMP:
        if (currentFrame > imageData->frameCount) currentFrame = imageData->frameCount - 1;
        std::cout << "STAGE: " << "STAY_JUMP" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::STAY_DROP:
        if (currentFrame > imageData->frameCount) currentFrame = imageData->frameCount - 1;
        std::cout << "STAGE: " << "STAY_DROP" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::STAY_SITTING:
        if (currentFrame > imageData->frameCount) currentFrame = imageData->frameCount - 1;
        std::cout << "STAGE: " << "STAY_SITTING" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::RUN_RIGHT:
        dx = speed;
        if (currentFrame > imageData->frameCount) currentFrame -= imageData->frameCount;
        std::cout << "STAGE: " << "RUN_RIGHT" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * int(currentFrame) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::RUN_LEFT:
        dx = -speed;
        if (currentFrame > imageData->frameCount - 1 ) currentFrame -= imageData->frameCount - 1;
        std::cout << "STAGE: " << "RUN_LEFT" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * (int(currentFrame) + 1) , 0,  -imageData->W, imageData->H));
        break;

    case STAGE::RUN_JUMP:
        if (currentFrame > imageData->frameCount - 1 ) currentFrame -= imageData->frameCount - 1;
        std::cout << "STAGE: " << "RUN_JUMP" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * (int(currentFrame) + 1) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::RUN_DROP:
        if (currentFrame > imageData->frameCount - 1 ) currentFrame = imageData->frameCount - 1;
        std::cout << "STAGE: " << "RUN_DROP" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * (int(currentFrame) + 1) , 0,  imageData->W, imageData->H));
        break;

    case STAGE::RUN_SITTING:
        if (currentFrame > imageData->frameCount - 1 ) currentFrame -= imageData->frameCount - 1;
        std::cout << "STAGE: " << "RUN_SITTING" << std::endl;
        std::cout << "Current Frame: " << currentFrame << std::endl;
        sprite.setTextureRect(sf::IntRect(imageData->W * (int(currentFrame) + 1) , 0,  imageData->W, imageData->H));
        break;

    default:
        break;

    }

    //sprite.setTextureRect(sf::IntRect(imageData->W * (int(currentFrame) + 1) , 0,  imageData->W, imageData->H));

    std::cout << "SPEED: " << speed << std::endl;

    std::cout << "X :" << x << std::endl;
    std::cout << "Dx:" << dx << std::endl;
    std::cout << "Y :" << y << std::endl;
    std::cout << "Dy:" << dy << std::endl;

    x += dx*time;
    checkCollicionWithMap(dx, 0);

    y += dy*time;
    checkCollicionWithMap(0, dy);

    //sprite.setPosition(x + w / 2, y + h / 2);

    std::cout << "X :" << x << std::endl;
    std::cout << "Dx:" << dx << std::endl;
    std::cout << "Y :" << y << std::endl;
    std::cout << "Dy:" << dy << std::endl;

    sprite.setPosition(x , y + h / 2);

    //std::cout << "POSITION: " << x << " " << y << std::endl;

    if (health <= 0){ life = false; }

    //if (!isMove){ speed = 0; }

    //setPlayerCoordinateForView(x, y);

    //if (life) { setPlayerCoordinateForView(x, y); }

    dy = dy + 0.0015*time;

    //if(dx>0) sprite.scale(-1, 1);
    //if(dx<0) sprite.scale(-1, 1);

}

void Player::checkCollicionWithMap(float Dx, float Dy)
{
    for (int i = 0; i<obj.size(); i++)//проходимся по объектам
        if (getRect().intersects(obj[i].rect))//проверяем пересечение игрока с объектом
        {
            if (obj[i].type == "solid"){//если встретили препятствие (объект с именем solid)

                if (Dy>0)	{
                    y = obj[i].rect.top - h;
                    dy = 0;
                    onGround = true;
                }
                if (Dy<0)	{
                    y = obj[i].rect.top + obj[i].rect.height;
                    dy = 0;
                }

                if (Dx>0)	{
                    //x = obj[i].rect.left - w;
                    //dx = -0.1;
                    //sprite.scale(-1, 1);
                }
                if (Dx<0)	{
                    //x = obj[i].rect.left + obj[i].rect.width;
                    //dx = 0.1;
                    //sprite.scale(-1, 1);
                }
            }
        }
}

