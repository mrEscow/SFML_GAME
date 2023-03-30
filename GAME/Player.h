#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "ResourcesManager.h"

class Player : public AGameObject
{
    Image* image;//создаем объект Texture (текстура)

    sf::Sprite sprite; //создаем объект Sprite(спрайт)

    float currentFrame = 0;//хранит текущий кадр

    int dir = 1; //направление (direction) движения игрока

    float dx = 0.1;
    float dy = 0;

    bool onGround;

    float speedMove = 50;

    float speedAnimation = 0.05f;

public:
    Player();

    enum class STAGE{
        REST,
        RUNonRIght,
        RUNonLEFT,
        JUMP
    }Stage;

    // AGameObject interface
public:
    virtual void Action() override;
    virtual void Update(const float& time) override;
    virtual void Draw() override;

private:
    void setImageDate(std::string imageName);
    void checkCollicionWithMap();

};

#endif // PLAYER_H
