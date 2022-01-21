#pragma once;
#include "IAecs.hpp"

// Every Component should also be included in the enum, and store the enum number in itself
namespace IA::ECS {
    enum Components {};
    
    struct Component {
        Components type;
    };
}