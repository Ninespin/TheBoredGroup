#pragma once
#include <iostream>
#include "Scene.h"
#include "Component.h"

namespace Bore{
    // Base renderer class
    class BoreRenderer{
    public:
        GLuint shaderProgram;
        GLint mvp_location, vpos_location, vcol_location;
    public:
        BoreRenderer();
        ~BoreRenderer();
        void Render(Scene::Scene* scene);
    };
}
