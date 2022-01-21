#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <algorithm>

namespace IA::ECS {
    struct System {
        std::vector<Components> components; // list of component types that an entity should have for this system to operate on it
        std::vector<Entity*> entities; // List of eneities that this system is operating on
        
        // Checks if this system should care about this entity
        bool check(Entity* entity) {
            bool cares = true;
            for (Components c:components) {
                if (std::find(entity->components.begin(), entity->components.end(), c) == entity->components.end()) {
                    cares = false;
                    break;
                }
            }
            return cares;
        }

        // Calls update() on each of this system's entities. Returns true if the current update cycle should stop.
        virtual bool update_all() {
            for (Entity* entity:entities) {
                if (update(entity)) return true;
            }
            return false;
        }
        
        // Updates an entity with whatever this system does. Returns true if the current update cycle should stop.
        virtual bool update(Entity* entity) {
            return false;
        }
    };
}