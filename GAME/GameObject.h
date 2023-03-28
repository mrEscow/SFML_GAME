#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class AGameObject
{
public:
    virtual void Action(){};

    virtual void Update(const float& time){};

    virtual void Draw(){};

    //virtual ~AGameObject();
};

#endif // GAMEOBJECT_H
