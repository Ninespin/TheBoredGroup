#include "BoreRenderer.h"
namespace Bore{
    BoreRenderer::BoreRenderer(){

    }
    BoreRenderer::~BoreRenderer(){

    }

    // main exposed render method
    //
    void BoreRenderer::Render(){
        fprintf(stdout, "Render.\n");
    }
}
