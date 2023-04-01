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

                            MapObject tile;

                            tile.id = object["id"];

                            tile.gid = object["gid"];
                            tile.gid--;

                            tile.name = object["name"];
                            tile.type = object["type"];

                            tile.rotation = object ["rotation"];

                            tile.visible = object ["visible"];


                            tile.rect.left = object["x"];
                            tile.rect.top = object["y"];
                            tile.rect.width = object["width"];
                            tile.rect.height = object["height"];

                            tilesFromMap.push_back(tile);

                        }
                    }
                }
            }
        }
    }
}
