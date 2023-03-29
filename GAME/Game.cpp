#include "Game.h"


#include "imgui.h"
#include "imgui-SFML.h"

#include "Window.h"
#include "Define.h"
#include "GameObject.h"
#include "BackGround.h"
#include "Tile.h"
#include "GreenWarior.h"
#include "Player.h"


// s - stop

char grid[16][32] = {
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'},
    {'s',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','s'}
};

Game::Game()
{  
    if(ImGui::SFML::Init(*WND)){}
    WND->setTitle(windowTitle);

    gameObjects.push_back(std::make_unique<BackGround>());


    for (int i = 0; i < 5; ++i) {
        sf::Vector2f pos = {static_cast<float>(250 + ( i* 64)) ,350};
        gameObjects.push_back(std::make_unique<Tile>(pos));
    }


    gameObjects.push_back(std::make_unique<GreenWarior>());
    gameObjects.push_back(std::make_unique<Player>());
}

void Game::play(){
    while (WND->isOpen()) {

        float time = deltaClock.getElapsedTime().asMicroseconds();
        time = time / 800;

        sf::Event event;
        while (WND->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                WND->close();
            }

            for(auto& object:gameObjects)
                object->Action();
        }

        for(auto& object:gameObjects)
            object->Update(time);

        ImGui::SFML::Update(*WND, deltaClock.restart());

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
            WND->setTitle(windowTitle);
        }
        ImGui::End(); // end window

        WND->clear(bgColor); // заполняем окно заданным цветом

        for(auto& object:gameObjects)
            object->Draw();

        ImGui::SFML::Render(*WND);

        WND->display();
    }

    ImGui::SFML::Shutdown();
}

Game::~Game()
{
    gameObjects.clear();
}
