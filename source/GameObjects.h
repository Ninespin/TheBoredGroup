#pragma once
#include <string>
#include <map>
#include <memory>
#include "Component.h"
#include "RenderProperties.h"

namespace GameObjects{
    class GameObject{
    public:
        std::string name;
        GameObject* parent;
        std::map<std::string, std::shared_ptr<Component>> components;
    public:
        GameObject(std::string name = "DefaultGameObject");
        virtual ~GameObject();
    };

    class RenderableObject:public GameObject{
    public:
        RenderableObject(std::string name="DefaultRenderable");
        ~RenderableObject();
    };
};
