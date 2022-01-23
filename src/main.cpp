#include "IAecs.hpp"
using namespace IA;

ECS::App app;

int main() {
    app = ECS::App(800, 600, "Game");
    app.add_world("title", new ECS::World());
    app.activeWorld->add_entity(ECS::E::Player());
    return 0;
}