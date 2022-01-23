#pragma once;
#include "IAecs.hpp"
#include <vector>
#include <map>
#include <string>

namespace IA::ECS::E {
    struct Entity {
        std::vector<std::string> componentTypes; // Stores a list of the component types that this entity should have. This is not enforced.
        std::map<std::string, C::Component*> components; // Maps a component type to an actual component object

        // Blank Constructor
        Entity() {

        }

        // Construct from component types
        Entity(std::vector<std::string> _componentTypes) {
            componentTypes = _componentTypes;
        }

        // Construct from components (infers types as well)
        Entity(std::vector<C::Component*> _components) {
            for (C::Component* c:_components) {
                componentTypes.push_back(c->type);
                components[c->type] = c;
            }
        }

        // Returns a component by type
        C::Component* get_component(std::string type) {
            return components[type];
        }

        // Adds a component. Doesn't check if it should have a component of this type.
        void add_component(C::Component* component) {
            components[component->type] = component;
        }
    };
}