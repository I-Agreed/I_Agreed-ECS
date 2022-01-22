#pragma once
#include "../IAecs.hpp"
#include <string>

// Component that displays a sprite or animation in the place of the entity

namespace IA::ECS::C {

    struct Display:Component {
        std::string spriteName;

        // Blank Constructor
        Display():Component() {
            type = "Display";
        }

        // Construct with sprite name
        Display(std::string sprite):Component() {
            type = "Display";
            spriteName = sprite;
        }
    };
}