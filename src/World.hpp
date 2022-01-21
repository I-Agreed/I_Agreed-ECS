#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <algorithm>

namespace IA::ECS {
    struct World {
        std::vector<Entity*> entities; // Entities within this world
        std::vector<Entity*> entitiesToRemove; // Entities marked for removal

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
                    entitiesToRemove.push_back(entity);
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

        // Removes all entities marked for removal
        void remove_marked_entities() {
            for (Entity* entity:entitiesToRemove) {
                actually_remove_entity(entity);
            }
            entitiesToRemove.clear();
        }

        // Calls update_all on each system, then removes entities.
        void update() {
            for (System* system:systems) {
                system->update_all();
            }
            remove_marked_entities();
        }
    };
}