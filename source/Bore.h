#pragma once
#include "BoreRenderer.h"
#include "BoreUpdater.h"

namespace Bore{
    // Core engine class
    class Bore{
        BoreUpdater updater;
        BoreRenderer renderer;
    public:
        Bore();
        ~Bore();
        void Render();
        void Update();
    };



}
