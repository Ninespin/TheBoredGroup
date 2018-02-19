#pragma once
#include <string>
#include <vector>
#include "RenderProperties.h"

namespace GameObjects{
    class GameObject{
    public:
        std::string name;
        GameObject* parent;
    public:
        GameObject(std::string name = "DefaultGameObject");
        ~GameObject();
    };

    class RenderableObject:public GameObject{
    public:
        std::vector<RenderProperties::RenderProperties> renderProperties;
    public:
        RenderableObject(std::string name="DefaultRenderable");
        ~RenderableObject();
    };
};
