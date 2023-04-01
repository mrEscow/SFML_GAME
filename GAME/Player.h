#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"



class Player : public AGameObject
{
    enum class STAGE{

        STAY,
        STAY_JUMP,
        STAY_DROP,
        STAY_SITTING,

        RUN_RIGHT,
        RUN_LEFT,
        RUN_JUMP,
        RUN_DROP,
        RUN_SITTING

    }Stage;

    float speedMove = 10;

    float speedAnimation = 0.05f;


    bool isStayJump{false};
    bool isStaySitting{false};

public:
    Player(std::vector<MapObject> mapObject);



    // AGameObject interface
public:
    virtual void Action() override;
    virtual void Update(const float& time) override;

private: 
    void checkCollicionWithMap(float Dx, float Dy);

};

#endif // PLAYER_H
