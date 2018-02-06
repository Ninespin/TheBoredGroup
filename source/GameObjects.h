#pragma once
#include <string>

namespace GameObjects{
    class GameObject{
    public:
        std::string name;
        GameObject* parent;
    public:
        GameObject(std::string name = "");
        ~GameObject();
    };

};
