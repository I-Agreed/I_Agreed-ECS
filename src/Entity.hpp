#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <map>
#include <string>

namespace IA::ECS {
    struct Entity {
        std::vector<std::string> componentTypes; // Stores a list of the component types that this entity should have
        std::map<std::string, C::Component*> components; // Maps a component type to an actual component object

        C::Component* get_component(std::string type) {
            return components[type];
        }

        void add_component(C::Component* component) {
            components[component->type] = component;
        }
    };
}