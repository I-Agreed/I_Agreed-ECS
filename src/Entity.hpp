#pragma once;
#include "IAecs.hpp"
#include <vector>

namespace IA::ECS {
    struct Entity {
        std::vector<Components> components; // Stores a list of the component types that this entity should have
    };
}