#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

class Player : public AGameObject
{
    sf::Texture texturaREST;//создаем объект Texture (текстура)
    sf::Texture texturaRUN;//создаем объект Texture (текстура)
    sf::Sprite sprite; //создаем объект Sprite(спрайт)

    float currentFrame = 0;//хранит текущий кадр

    int dir = 1; //направление (direction) движения игрока

public:
    Player();

    enum class STAGE{
        REST,
        RUN
    }Stage;

    // AGameObject interface
public:
    virtual void Action() override;
    virtual void Update(const float& time) override;
    virtual void Draw() override;
};

#endif // PLAYER_H
