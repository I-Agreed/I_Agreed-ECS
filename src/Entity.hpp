#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <map>

namespace IA::ECS {
    struct Entity {
        std::vector<Components> componentTypes; // Stores a list of the component types that this entity should have
        std::map<Components, Component*> components; // Maps a component type to an actual component object

        Component* get_component(Components type) {
            return components[type];
        }

        void add_component(Component* component) {
            components[component->type] = component;
        }
    };
}