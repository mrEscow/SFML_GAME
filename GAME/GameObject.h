#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class AGameObject
{
public:
    virtual void Action(){};
    virtual void Update(){};
    virtual void Draw(){};
};

#endif // GAMEOBJECT_H
