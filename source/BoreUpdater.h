#pragma once
#include <stdio.h>

namespace Bore{
    // Base updater class
    class BoreUpdater{
    public:
        BoreUpdater();
        ~BoreUpdater();
        void Update();
    };
}
