#include "Game.h"

#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

#include "imgui.h"
#include "imgui-SFML.h"

class BackGround : public AGameObject
{
    sf::RenderWindow* window;

    sf::Sprite sprite;
public:
    BackGround(sf::RenderWindow* window){
        this->window = window;
        sf::Texture textura;
        textura.loadFromFile("SFML_GAME/GAME/Images/BackGround.jpg"); // TODO THIS FIX IN FIRST TIME
        sprite.setTexture(textura);
    }

    virtual void Draw() override{
        window->draw(sprite);
    };
};

Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(640, 480), "");
    window->setVerticalSyncEnabled(true);
    if(ImGui::SFML::Init(*window)){}
    window->setTitle(windowTitle);

    gameObjects.push_back(new BackGround(window));
}

void Game::play(){
    while (window->isOpen()) {
        sf::Event event;
        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window->close();
            }

            for(auto& object:gameObjects)
                object->Action();
        }

        for(auto& object:gameObjects)
            object->Update();

        ImGui::SFML::Update(*window, deltaClock.restart());

        ImGui::Begin("Sample window"); // создаём окно

        // Инструмент выбора цвета
        if (ImGui::ColorEdit3("Background color", color)) {
            // код вызывается при изменении значения, поэтому всё
            // обновляется автоматически
            bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }

        ImGui::InputText("Window title", windowTitle, 255);

        if (ImGui::Button("Update window title")) {
            // этот код выполняется, когда юзер жмёт на кнопку
            // здесь можно было бы написать
            // if(ImGui::InputText(...))
            window->setTitle(windowTitle);
        }
        ImGui::End(); // end window

        window->clear(bgColor); // заполняем окно заданным цветом

        for(auto& object:gameObjects)
            object->Draw();

        ImGui::SFML::Render(*window);
        window->display();
    }

    ImGui::SFML::Shutdown();
}

Game::~Game(){
    delete window;
}
