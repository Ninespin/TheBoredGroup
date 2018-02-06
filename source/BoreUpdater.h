#pragma once
#include <iostream>
#include "Scene.h"

namespace Bore{
    // Base updater class
    class BoreUpdater{
    public:
        BoreUpdater();
        ~BoreUpdater();
        void Update(Scene::Scene* scene);
    };
}
