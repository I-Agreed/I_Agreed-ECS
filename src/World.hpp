#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <algorithm>

namespace IA::ECS {
    struct World {
        std::vector<Entity*> entities; // Entities within this world
        std::vector<System*> systems; // Entities within this world

        // Add an entity to this world
        void add_entity(Entity* entity) {
            for (System* system:systems) {
                if (system->check(entity)) {
                    system->entities.push_back(entity);
                }
            }
        }

        // Mark an entity for removal
        void remove_entity(Entity* entity) {
            for (System* system:systems) {
                if (system->check(entity)) {
                    system->entities.push_back(entity);
                }
            }
        }
        
        // Actually remove an entity, don't directly call
        void actually_remove_entity(Entity* entity) {
            for (System* system:systems) {
                if (system->check(entity)) {
                    system->entities.erase(std::remove(system->entities.begin(), system->entities.end(), entity), system->entities.end());
                }
            }
        }

        void update() {
            for (System* system:systems) {
                system->update_all();
            }
        }
    };
}