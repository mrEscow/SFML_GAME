#include "Player.h"
#include "Define.h"
#include "Window.h"


#include <SFML/Graphics.hpp>

Player::Player(std::vector<std::string> tileMap)
{
    this->tileMap = tileMap;

    Stage = STAGE::REST;

    setImageDate("PlayerRest");


    sprite.setPosition(250, 250);



    onGround = true;
}

void Player::Action()
{
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W))) && (onGround)) {
        Stage = STAGE::JUMP;
        setImageDate("PlayerRun");
        dir = 0;
        dy = -0.18;
        onGround = false;
    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
        Stage = STAGE::RUNonRIght;
        setImageDate("PlayerRun");
        dir = 1;

    }
    else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
        Stage = STAGE::RUNonLEFT;
        setImageDate("PlayerRun");
        dir = -1;

    }
    else{
        Stage = STAGE::REST;
        setImageDate("PlayerRest");
        dir = 0;

    }
}

void Player::Update(const float& time)
{

    currentFrame += speedAnimation * time ;

    switch (Stage) {

    case STAGE::REST:
        dir = 0;
        if (currentFrame > image->frameCount) currentFrame -= image->frameCount;
        sprite.setTextureRect(sf::IntRect(image->X * int(currentFrame) , 0,  image->X, image->Y));
        break;

    case STAGE::RUNonRIght:
        dir = 1;
        if (currentFrame > image->frameCount) currentFrame -= image->frameCount;
        sprite.setTextureRect(sf::IntRect(image->X * int(currentFrame) , 0,  image->X, image->Y));
        break;

    case STAGE::RUNonLEFT:
        dir = -1;
        if (currentFrame > image->frameCount - 1 ) currentFrame -= image->frameCount - 1;
        sprite.setTextureRect(sf::IntRect(image->X * (int(currentFrame) + 1) , 0,  -image->X, image->Y));
        break;

    case STAGE::JUMP:
        dir = 0;
        if (currentFrame > image->frameCount) currentFrame -= image->frameCount;
        sprite.setTextureRect(sf::IntRect(image->X * int(currentFrame) , 0,  image->X, image->Y));
        break;

    default:
        break;

    }    

    rect.left = sprite.getPosition().x;
    rect.top = sprite.getPosition().y;

    checkCollicionWithMap();

    if(onGround) dy = 0;
    else dy = dy + 0.00015 * time;




    sprite.move(dir * dx * speedMove, dy * speedMove);

}

void Player::Draw()
{
    WND->draw(sprite);
}

void Player::setImageDate(std::string imageName)
{
    image = RES->getImage(imageName);

    if(!image){
        std::cout << "IMGE ERROR! " << " PLAYER" << "NAME: " << imageName;
        return;
    }

    sprite.setTexture(image->textura);
    //sprite.setOrigin(image->X/2,image->Y/2);
    sprite.setTextureRect(sf::IntRect(0, 0, image->X, image->Y));

    rect = sf::FloatRect(0,0, image->X, image->Y);
}

void Player::checkCollicionWithMap()
{
    for (int i = rect.top/64; i < (rect.top + rect.height)/64; ++i) {
        for (int j = rect.left/64; j<(rect.left + rect.width)/64; j++){
            if(tileMap[i][j] =='p'){
                if (dy > 0)
                    onGround=true;

            }
            else
               onGround = false;
        }
    }
}

