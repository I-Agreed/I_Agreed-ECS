#pragma once

#include "../IAecs.hpp"

//Entity that represents the controllable player character
// Component types: Display, Transform

namespace IA::ECS::E {
        Entity* Player() {
            std::vector<C::Component*> components = {
                new C::Display(),
                new C::Transform()
            };
            return new Entity(components);
        }
}