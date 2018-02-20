#pragma once
#include "GameObjects.h"

class PrintNameComponent:public Component{
public:
    PrintNameComponent();
    ~PrintNameComponent();
    int run(GameObjects::GameObject* parent)override;
    int init(GameObjects::GameObject* parent)override;
};
