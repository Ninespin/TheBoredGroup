#include "Scene.h"

namespace Scene{
    Scene::Scene(std::string name)
        : name(name)
        , objects()
    {
    }
    Scene::~Scene(){

    }

    std::string Scene::getName(){
        return this->name;
    }

};
