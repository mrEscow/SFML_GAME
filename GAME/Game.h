#ifndef GAME_H
#define GAME_H

#include <entt.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#include <vector>
#include <memory>


class Game
{

public:
    Game();

    void play();

    ~Game();

private:
    entt::registry registry;

    sf::Clock deltaClock;

    sf::Color bgColor;

    float color[3] = {0.f,  0.f, 0.f};

    char windowTitle[255] = "ImGui + Entt + SFML = <3";

    std::vector<class AGameObject*> gameObjects;

};

#endif // GAME_H
