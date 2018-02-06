#pragma once
#include <iostream>
#include "Scene.h"

namespace Bore{
    // Base renderer class
    class BoreRenderer{
    public:
        BoreRenderer();
        ~BoreRenderer();
        void Render(Scene::Scene* scene);
    };
}
