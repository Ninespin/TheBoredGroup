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

    GameObjects::GameObject* Scene::getGameObjectByName(std::string name){
        return &this->objects[name];
    }

    void Scene::addGameObject(GameObjects::GameObject& object){
        this->objects.insert(
            std::pair<std::string, GameObjects::GameObject>(object.name, object)
        );
    }

};
