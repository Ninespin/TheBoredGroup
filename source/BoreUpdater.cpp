#include "BoreUpdater.h"
namespace Bore{

    BoreUpdater::BoreUpdater(){

    }
    BoreUpdater::~BoreUpdater(){

    }

    // main exposed update method
    //
    void BoreUpdater::Update(Scene::Scene* scene){
        std::map<std::string, std::shared_ptr<GameObjects::GameObject>>* objects = scene->getGameObjects();
        for(std::map<std::string, std::shared_ptr<GameObjects::GameObject>>::iterator it = objects->begin();
                it != objects->end(); it++)
        {
            for(std::map<std::string, std::shared_ptr<Component>>::iterator comp = it->second->components.begin();
                    comp != it->second->components.end(); comp++)
            {
                comp->second->run(it->second.get());
            }
        }
    }
}
