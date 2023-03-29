#ifndef RESOURCESMANAGER_H
#define RESOURCESMANAGER_H

#include "SFML/Graphics/Texture.hpp"

#include <vector>

#include <filesystem>
#include <string>
#include <iostream>

namespace fs = std::filesystem;

struct Image{
    std::string name;
    sf::Texture textura;
    uint32_t frameCount;
    float X;
    float Y;
};


class ResourcesManager
{
public:
    ResourcesManager(ResourcesManager &other) = delete;

    void operator=(const ResourcesManager &) = delete;

    static ResourcesManager* Get();

    Image* getImage(std::string name);

protected:
    ResourcesManager();

private:
    static ResourcesManager* resourcesManager;

    std::vector<Image*> images;

    void loadTextures();
    std::vector<fs::path> serchImagesPaths();
    std::vector<fs::path> scanDirectory(std::string pathDir);
    void addTextura(fs::path path);
};

#endif // RESOURCESMANAGER_H
