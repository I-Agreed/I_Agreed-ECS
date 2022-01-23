#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <algorithm>

namespace IA::ECS::S {
    struct System {
        std::vector<std::string> components; // list of component types that an entity should have for this system to operate on it
        std::vector<E::Entity*> entities; // List of eneities that this system is operating on
        World* world; // Stores the world that holds this system

        // Blank Constructor
        System() {

        }
        
        // Checks if this system should care about this entity
        bool check(E::Entity* entity) {
            bool cares = true;
            for (std::string c:components) {
                if (std::find(entity->componentTypes.begin(), entity->componentTypes.end(), c) == entity->componentTypes.end()) {
                    cares = false;
                    break;
                }
            }
            return cares;
        }

        // Calls update() on each of this system's entities. Returns true if the current update cycle should stop.
        virtual bool update_all() {
            for (E::Entity* entity:entities) {
                if (update(entity)) return true;
            }
            return false;
        }
        
        // Updates an entity with whatever this system does. Returns true if the current update cycle should stop.
        virtual bool update(E::Entity* entity) {
            return false;
        }
    };
}