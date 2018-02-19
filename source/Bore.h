#pragma once
#include <map>
#include <memory>
#include <string>
#include "BoreRenderer.h"
#include "BoreUpdater.h"
#include "Scene.h"
#include "GameObjects.h"

namespace Bore{

    // Core engine class
    class Bore{
        BoreUpdater updater;
        BoreRenderer renderer;
        std::map<std::string, std::shared_ptr<Scene::Scene>> scenes;
        std::shared_ptr<Scene::Scene> currentScene;
    public:
        Bore();
        ~Bore();
        void Render();
        void Update();
        std::shared_ptr<Scene::Scene> getCurrentScene();
        void setCurrentScene(std::string name);
        void addScene(std::shared_ptr<Scene::Scene> scene);
    };



}
