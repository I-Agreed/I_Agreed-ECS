#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <algorithm>

namespace IA::ECS {
    struct World {
        std::vector<E::Entity*> entities; // Entities within this world
        std::vector<E::Entity*> entitiesToRemove; // Entities marked for removal

        std::vector<S::System*> systems; // Entities within this world

        App* app; // Stores the app that holds this system

        World() {
            init_systems();
        }

        // System process order is defined here, it may be important.
        void init_systems() {
            add_system(new S::Render());
        }

        // Add an entity to this world
        void add_entity(E::Entity* entity) {
            for (S::System* system:systems) {
                if (system->check(entity)) {
                    system->entities.push_back(entity);
                }
            }
        }

        // Mark an entity for removal
        void remove_entity(E::Entity* entity) {
            for (S::System* system:systems) {
                if (system->check(entity)) {
                    entitiesToRemove.push_back(entity);
                }
            }
        }
        
        // Actually remove an entity, don't directly call
        void actually_remove_entity(E::Entity* entity) {
            for (S::System* system:systems) {
                if (system->check(entity)) {
                    system->entities.erase(std::remove(system->entities.begin(), system->entities.end(), entity), system->entities.end());
                }
            }
        }

        // Removes all entities marked for removal
        void remove_marked_entities() {
            for (E::Entity* entity:entitiesToRemove) {
                actually_remove_entity(entity);
            }
            entitiesToRemove.clear();
        }

        // Adds a System
        void add_system(S::System* system) {
            system->world = this;
            systems.push_back(system);
        }

        // Calls update_all on each system, then removes entities.
        void update() {
            for (S::System* system:systems) {
                if (system->update_all()) break;
            }
            remove_marked_entities();
        }
    };
}