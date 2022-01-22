#pragma once
#include "../IAecs.hpp"
#include <string>

// Component that stores the location of an entity

namespace IA::ECS::C {

    struct Transform:Component {
        geo::Vector2i pos;
        
        // Blank Constructor
        Transform():Component() {
            type = "Transform";
        }

        // Construct with vector
        Transform(geo::Vector2i _pos):Component() {
            type = "Transform";
            pos = _pos;
        }
    };
}