#include "Game.h"


#include "imgui.h"
#include "imgui-SFML.h"

#include "Window.h"
#include "Define.h"

#include "GameObject.h"

#include "BackGround.h"
#include "Oblako.h"

#include "Tile.h"

#include "GreenWarior.h"
#include "Robot.h"

#include "Player.h"


#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"
using json = nlohmann::json;

struct TileData{

    int id;
    int gid;

    int height;
    int width;

    int x;
    int y;

    int rotation;

    std::string name;
    std::string type;

    bool visible;
};

class Map
{
    int height{0};
    int width{0};
    int tileheight{0};


    std::vector <TileData> tilesFromMap;


public:
    std::vector <TileData> getTilesData(){
        return tilesFromMap;
    };

    int main()
    {
        std::string path;
        const fs::path workdir = fs::current_path();
        const fs::path mapsPath = workdir / "Maps" ;
        std::string name = "Map#1.json";

        std::filesystem::directory_iterator iterator(mapsPath);
        for (; iterator != std::filesystem::end(iterator); iterator++)
            if (iterator->path().filename() == name)
                path = iterator->path().string();

        std::ifstream ifs{path};
        if (!ifs.is_open())
        {
            std::cerr << "Unable to open file\n";
            throw 1;
        }
        json j;
        ifs >> j;
        ifs.close();

        //std::cout << j << std::endl;

        if (j.find("height") != j.end())
        {
            height = j["height"];
            std::cout << "height: " << height << std::endl;
        }
        if (j.find("width") != j.end())
        {
            width = j["width"];
            std::cout << "width: " << width << std::endl;
        }
        if (j.find("tileheight") != j.end())
        {
            tileheight = j["tileheight"];
            std::cout << "tileheight: " << tileheight << std::endl;
        }



        for (auto const& layers : j["layers"])
        {
            if (layers.find("name") != layers.end())
            {
                if(layers["name"] == "Ground" ){
                    std::cout << "TRUE" << std::endl;
                    for (auto const& layer : layers)
                    {
                        if(layer.is_array()){
                            for (auto const& object : layer)
                            {
                                //std::cout << object << std::endl;
                                TileData tile;
                                tile.gid = object["gid"];
                                tile.gid--;
                                tile.x = object["x"];
                                tile.y = object["y"];

                                tilesFromMap.push_back(tile);

                            }
                        }
                    }
                }
            }
        }



        return 0;
    }
};

Game::Game()
{
    Map map;
    map.main();

    std::vector <TileData> tilesData = map.getTilesData();


    if(ImGui::SFML::Init(*WND)){}
    WND->setTitle(windowTitle);


    gameObjects.push_back(std::make_unique<BackGround>());
    gameObjects.push_back(std::make_unique<Oblako>());


    //    for (int i = 0; i < 5; ++i) {
    //        sf::Vector2f pos = {static_cast<float>(250 + ( i* 64)) ,350};
    //        gameObjects.push_back(std::make_unique<Tile>(pos));
    //    }

    //    for (int i = 0; i < 12; ++i) {
    //        sf::Vector2f pos = {static_cast<float>((250 + 256) + ( i* 64)) ,606};
    //        gameObjects.push_back(std::make_unique<Tile>(pos));
    //    }

    for (size_t i = 0; i < tilesData.size(); ++i) {

        sf::Vector2f pos = {static_cast<float>( tilesData[i].x) , static_cast<float>(tilesData[i].y)};

        gameObjects.push_back(std::make_unique<Tile>(pos, tilesData[i].gid));

    }


    gameObjects.push_back(std::make_unique<GreenWarior>());

    gameObjects.push_back(std::make_unique<Robot>());

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
