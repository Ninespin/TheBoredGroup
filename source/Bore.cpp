#include "Bore.h"

namespace Bore{
    Bore::Bore()
        : updater()
        , renderer()
    {
        
        this->scenes["default"] = Scene::Scene("default");
        this->currentScene = &this->scenes["default"];
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

}
