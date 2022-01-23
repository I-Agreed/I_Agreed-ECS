#pragma once
#include "../IAecs.hpp"

namespace IA::ECS::S {
    struct Render:System {

        // Blank Constructor
        Render():System() {
            components = {"Display", "Transform"};
        }
        
        // Updates an entity with whatever this system does. Returns true if the current update cycle should stop.
        virtual bool update(E::Entity* entity) {
            C::Display* display = dynamic_cast<C::Display*>(entity->get_component("Display"));
            world->app->window->draw(world->app->get_sprite(display->spriteName).get());
            return false;
        }
    };
}