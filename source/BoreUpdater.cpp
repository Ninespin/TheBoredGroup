#include "BoreUpdater.h"
namespace Bore{

    BoreUpdater::BoreUpdater(){

    }
    BoreUpdater::~BoreUpdater(){

    }

    // main exposed update method
    //
    void BoreUpdater::Update(Scene::Scene* scene){
        std::cout << "Updating " << scene->getName() << std::endl;
    }
}
