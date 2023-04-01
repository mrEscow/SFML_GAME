#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include "SFML/Graphics/Texture.hpp"

#include <vector>

#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

struct ImageData{
    std::string name;
    sf::Texture textura;
    uint32_t frameCount;
    float W;
    float H;
};


class ResourcesManager
{
public:
    ResourcesManager(ResourcesManager &other) = delete;

    void operator=(const ResourcesManager &) = delete;

    static ResourcesManager* Get();

    ImageData* getImage(std::string name);

protected:
    ResourcesManager();

private:
    static ResourcesManager* resourcesManager;

    std::vector<ImageData*> images;

    void loadTextures();
    std::vector<fs::path> serchImagesPaths();
    std::vector<fs::path> scanDirectory(std::string pathDir);
    void addTextura(fs::path path);
};

#endif // RESOURCESMANAGER_H
