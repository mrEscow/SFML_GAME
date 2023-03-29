#include "ResourcesManager.h"

#include <SFML/Graphics.hpp>
#include "SFML/Graphics/Texture.hpp"

/*

Для коректной работы поска текстур название тестуры должно включать:

    1) Коректное имя с большой буквы
    2) Далее через нижнее подчеркивание количество кадров
    3) И размер одного фрагмента

    Пример: GreenWarrior_24_186_189

    Примечание:
        Если картинка состоит из одного кадра: нужно указывать "0"
        Пример: Oblako_0_156_111

*/

ResourcesManager* ResourcesManager::resourcesManager = nullptr;

ResourcesManager* ResourcesManager::Get()
{
    if(resourcesManager == nullptr){
        resourcesManager = new ResourcesManager();
    }

    return resourcesManager;
}


Image* ResourcesManager::getImage(std::string name)
{
        Image* image;

        for(auto tmp : images)
            if(tmp->name == name)
                image = tmp;

        return image;
}

ResourcesManager::ResourcesManager()
{
    loadTextures();
}

void ResourcesManager::loadTextures()
{
    auto imagesPaths = serchImagesPaths();


    //images.resize(imagesPaths.size());

    for (size_t i = 0; i < imagesPaths.size(); ++i) {

        addTextura(imagesPaths[i]);
    }


}

std::vector<fs::path> ResourcesManager::serchImagesPaths()
{
    // Получаем текущий путь процесса (a.k.a. working directory)
    const fs::path workdir = fs::current_path();

    // Конструируем путь с помощью перегруженного оператора /
    const fs::path imagesPath = workdir / "Images";

    // Вызываеи рекурсивный метод поиска
    std::vector<fs::path> imagesPaths = scanDirectory(imagesPath.string());

    // Врзвращаем пути к картинкам
    return imagesPaths;
}

std::vector<fs::path> ResourcesManager::scanDirectory(std::string pathDir)
{
    std::vector<fs::path> filesA;

    std::string extension1 = ".png";
    std::string extension2 = ".jpg";
    std::string extension3 = ".jpeg";

    std::filesystem::directory_iterator iterator(pathDir);

    for (; iterator != std::filesystem::end(iterator); iterator++)
    {
        if(iterator->is_directory()){
             std::vector<fs::path> filesB = scanDirectory(iterator->path().string());

            filesA.insert(std::end(filesA), std::begin(filesB), std::end(filesB));
        }

        if (iterator->path().extension() == extension1)
            filesA.push_back(iterator->path().string());
        if (iterator->path().extension() == extension2)
            filesA.push_back(iterator->path().string());
        if (iterator->path().extension() == extension3)
            filesA.push_back(iterator->path().string());
    }

    return filesA;
}

void ResourcesManager::addTextura(std::filesystem::path path)
{
    std::string name;
    std::string frameCount;
    std::string X;
    std::string Y;

    std::string fullname = path.filename().string();

    bool isName = true;
    bool isFrameCount = true;
    bool isX = true;
    bool isY = true;

    for (size_t i = 0; i < fullname.size(); ++i) {
        if(isName){
            if(fullname[i] == '_'){
                isName = false;
                continue;
            }
            else{
                name += fullname[i];
                continue;
            }
        }

        if(isFrameCount){
            if(fullname[i] == '_'){
                isFrameCount = false;
                continue;
            }
            else{
                frameCount += fullname[i];
                continue;
            }
        }

        if(isX){
            if(fullname[i] == '_'){
                isX = false;
                continue;
            }
            else{
                X += fullname[i];
                continue;
            }
        }

        if(isY){
            if(fullname[i] == '.'){
                isY = false;
                continue;
            }
            else{
                Y += fullname[i];
                continue;
            }
        }
    }

    std::cout << "Name: " << name << std::endl;
    std::cout << "FrameCount: " << frameCount << std::endl;
    std::cout << "X: " << X << std::endl;
    std::cout << "Y: " << Y << std::endl;


    Image* image = new Image();
    image->name = name;
    image->frameCount = std::stoul(frameCount);
    image->X = std::stof(X);
    image->Y = std::stof(Y);

    image->textura.loadFromFile(path.string());


    images.push_back(image);


    std::cout << "------" << std::endl;

}
