#pragma once
#include <map>
#include <memory>
#include "GameObjects.h"

namespace Scene{
    class Scene{
        std::string name;
        std::map<std::string, std::shared_ptr<GameObjects::GameObject>> objects;
    public:
        Scene(std::string name = "");
        ~Scene();
        std::string getName();
        std::shared_ptr<GameObjects::GameObject> getGameObjectByName(std::string name);
        std::map<std::string, std::shared_ptr<GameObjects::GameObject>>* getGameObjects();
        void addGameObject(std::shared_ptr<GameObjects::GameObject> object );
    };
};
