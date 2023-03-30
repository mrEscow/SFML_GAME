#include "Map.h"

Map::Map(std::string mapName)
{
    nameMap = mapName;

    load(nameMap);
}

void Map::load(std::string mapName)
{
    nameMap = mapName;

    std::string path;
    const fs::path workdir = fs::current_path();
    const fs::path mapsPath = workdir / "Maps" ;

    std::filesystem::directory_iterator iterator(mapsPath);
    for (; iterator != std::filesystem::end(iterator); iterator++)
        if (iterator->path().filename() == nameMap)
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
    createTileMap();
}

void Map::createTileMap()
{
    tileMap.clear();

    for (int y = 0; y < height; ++y) {
        std::string str;
        bool isColision = false;
        for (int x = 0; x < width; ++x) {
            for (size_t idx = 0; idx < tilesFromMap.size(); ++idx) {
                if( y * 64 == tilesFromMap[idx].y && x * 64 == tilesFromMap[idx].x){
                    str += 'p';
                    isColision = true;
                    break;
                }
                else isColision = false;
            }

            if(!isColision){
                str += ' ';
            }
        }
        tileMap.push_back(str);
    }

}
