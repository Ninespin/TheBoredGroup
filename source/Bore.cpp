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
        this->renderer.Render();
    }

    void Bore::Update(){
        this->updater.Update();
    }

}
