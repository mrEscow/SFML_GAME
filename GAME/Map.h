#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <string>
#include <fstream>

#include "SFML/Graphics/Texture.hpp"

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include <filesystem>
namespace fs = std::filesystem;

struct MapObject{

    int id;
    int gid;

    sf::FloatRect rect;

    float rotation;

    std::string name;
    std::string type;

    bool visible;
};

class Map
{
    std::string nameMap;

    int height{0};
    int width{0};
    int tileheight{0};

    std::vector <MapObject> allObjectsFromMap;

public:
    Map(std::string mapName);

public:
    std::vector <MapObject> getAllObjectsDataFromMap(){
        return allObjectsFromMap;
    }

    void load(std::string mapName);
};

#endif // MAP_H
