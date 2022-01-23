// include all entity archetypes
// All entities are of one type, and just use different constructing methods to make them from an archetype

/* Archetype Template
//Entity that does something
// Component types: A, B, C

namespace IA::ECS::E {
        Entity* X() {
            std::vector<C::Component*> components = {
                
            };
            return new Entity(components);
        }
}
*/

#pragma once

#include "Player.hpp"