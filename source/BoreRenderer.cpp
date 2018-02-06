#include "BoreRenderer.h"
namespace Bore{
    BoreRenderer::BoreRenderer(){

    }
    BoreRenderer::~BoreRenderer(){

    }

    // main exposed render method
    //
    void BoreRenderer::Render(Scene::Scene* scene){
        std::cout << "Rendering " << scene->getName() << std::endl;
    }
}
