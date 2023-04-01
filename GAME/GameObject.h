#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <vector>
#include <string>

#include "Map.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

#include "Define.h"
#include "Window.h"

#include "ResourcesManager.h"

class AGameObject
{
protected:
    std::vector<MapObject> obj;//вектор объектов карты

    ImageData* imageData = nullptr;

    sf::Sprite sprite;

    sf::FloatRect rect;

    float dx, dy, x, y, speed, moveTimer;

    int w,h,health;

    bool life, isMove, onGround;

    float currentFrame = 0;//хранит текущий кадр


public:
    AGameObject(std::string imageName, float X = 0, float Y = 0){

        setImageDate(imageName);

        if(!imageData){
            std::cout << "Error: " << "ImageDate is NULL" << std::endl;
            return;
        }

        std::cout << "ImageDateName: " << imageData->name << std::endl;

        x = X; y = Y;

        h = imageData->W;
        w = imageData->H;


        moveTimer = 0;
        speed = 0.01;

        health = 100;

        //dx = 0; dy = 0;

        life = true;
        onGround = false;
        isMove = false;


        //sprite.setOrigin(w / 2, h / 2);
    }

    //virtual ~AGameObject();

    virtual void Action(){}

    virtual void Update(const float& time){}

    virtual void Draw(){WND->draw(sprite);}

protected:
    sf::FloatRect getRect(){//ф-ция получения прямоугольника. его коорд,размеры (шир,высот).
        return sf::FloatRect(x, y, w, h);//эта ф-ция нужна для проверки столкновений
    }

    void setImageDate(std::string imageName, float scaleX = 1, float scaleY = 1)
    {
        if(imageData)
            if(!imageData->name.empty())
                if(imageData->name == imageName){
                    return;
                }


        imageData = RES->getImage(imageName);

        if(!imageData){
            std::cout << "Error: " << "ImageDate is NULL" << std::endl;
            return;
        }

        std::cout << "ImageDateName: " << imageData->name << std::endl;

        sprite.setTexture(imageData->textura);
        sprite.setOrigin(imageData->W/2 ,imageData->H/2);
        sprite.setTextureRect(sf::IntRect(0, 0, imageData->W, imageData->H));

        sprite.setScale(scaleX, scaleY);

        w = imageData->W / scaleX;
        h = imageData->H / scaleY;

        currentFrame = 0;
    }
};

#endif // GAMEOBJECT_H
