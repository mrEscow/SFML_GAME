#include <entt.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <vector>

class AGameObject
{
public:
    virtual void Action(){};
    virtual void Update(){};
    virtual void Draw(){};
};


class Game
{
    entt::registry registry;

    sf::RenderWindow* window;

    sf::Clock deltaClock;

    sf::Color bgColor;

    float color[3] = {0.f,  0.f, 0.f};

    char windowTitle[255] = "ImGui + Entt + SFML = <3";

    std::vector<AGameObject*> gameObjects;

public:
    Game();

    void play();

    ~Game();
};
