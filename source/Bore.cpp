#include "Bore.h"

namespace Bore{
    Bore::Bore()
        : updater()
        , renderer()
    {

    }

    Bore::~Bore(){

    }

    void Bore::Render(){
        this->renderer.Render(this->getCurrentScene());
    }

    void Bore::Update(){
        this->updater.Update(this->getCurrentScene());
    }

    Scene::Scene* Bore::getCurrentScene(){
        return this->currentScene;
    }
    void Bore::setCurrentScene(std::string name){
        this->currentScene = &this->scenes[name];
    }
    void Bore::addScene(Scene::Scene& scene){
        this->scenes[scene.getName()] = scene;
    }


}
