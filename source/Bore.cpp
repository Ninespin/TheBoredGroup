#include "Bore.h"

namespace Bore{
    Bore::Bore()
        : updater()
        , renderer()
    {

    }

    Bore::~Bore(){

    }

    void Bore::Render(){
        fprintf(stdout, "Render.\n");
    }

    void Bore::Update(){
        fprintf(stdout, "Update.\n");
    }

}
