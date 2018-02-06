#pragma once
#include <map>
#include "GameObjects.h"

namespace Scene{
    class Scene{
        std::string name;
        std::map<std::string, GameObjects::GameObject> objects;
    public:
        Scene(std::string name = "");
        ~Scene();
    };
};
