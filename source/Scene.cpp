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

    std::shared_ptr<GameObjects::GameObject> Scene::getGameObjectByName(std::string name){
        return this->objects[name];
    }

    std::map<std::string, std::shared_ptr<GameObjects::GameObject>>* Scene::getGameObjects(){
        return &this->objects;
    }

    void Scene::addGameObject(std::shared_ptr<GameObjects::GameObject> object){
        this->objects.insert(
            std::pair<std::string, std::shared_ptr<GameObjects::GameObject>>(object->name, object)
        );
    }

};
