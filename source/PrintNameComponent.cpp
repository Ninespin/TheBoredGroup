#include "PrintNameComponent.h"
#include <iostream>

PrintNameComponent::PrintNameComponent()
{
}
PrintNameComponent::~PrintNameComponent()
{
}

int PrintNameComponent::run(GameObjects::GameObject* parent)
{
    std::cout << parent->name << std::endl;
    return 0;
}

int PrintNameComponent::init(GameObjects::GameObject* parent)
{
    return 0;
}
