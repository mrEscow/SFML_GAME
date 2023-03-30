#ifndef MAP_H
#define MAP_H


#include <iostream>
#include <string>
#include <fstream>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

#include <filesystem>
namespace fs = std::filesystem;

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
    std::string nameMap;

    int height{0};
    int width{0};
    int tileheight{0};

    std::vector <TileData> tilesFromMap;

    std::vector<std::string> tileMap;

public:
    Map(std::string mapName);

public:
    std::vector <TileData> getTilesData(){
        return tilesFromMap;
    };

    std::vector<std::string> getTileMap(){
        return tileMap;
    };

    void load(std::string mapName);

private:
    void createTileMap();
};

#endif // MAP_H
