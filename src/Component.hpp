#pragma once;
#include "IAecs.hpp"
#include <string>


namespace IA::ECS::C {
    
    struct Component {
        std::string type;

        // Blank Constructor
        Component() {

        }

        virtual void get_data() {

        }
    };
}