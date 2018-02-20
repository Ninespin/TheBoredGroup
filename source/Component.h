#pragma once
#include <string>
#include "GameObjects.h"

namespace GameObjects{
    class GameObject;
};

class Component{
public:
     std::string name;
public:
    Component();
    ~Component();
    virtual int run(GameObjects::GameObject* parent) = 0;
    virtual int init(GameObjects::GameObject* parent) = 0;
};
