#pragma once
#include <stdio.h>

namespace Bore{
    // Base renderer class
    class BoreRenderer{
    public:
        BoreRenderer();
        ~BoreRenderer();
        void Render();
    };
}
