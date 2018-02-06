#pragma once
#include <map>
#include <string>,
#include "BoreRenderer.h"
#include "BoreUpdater.h"
#include "Scene.h"
#include "GameObjects.h"

namespace Bore{
    // Core engine class
    class Bore{
        BoreUpdater updater;
        BoreRenderer renderer;
        std::map<std::string, Scene::Scene*> scenes;
    public:
        Bore();
        ~Bore();
        void Render();
        void Update();
    };



}
