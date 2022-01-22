#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

// Stores a sprite, or multiple sprites in an animation that can be drawn.

namespace IA::ECS {
    struct Sprite {
        std::vector<sf::Sprite*> sprites;
        int frame; // current animation frame
        int length; // number of frames

        Sprite(std::vector<sf::Sprite*> _sprites, int _length) {
            sprites = _sprites;
            length = _length;
            frame = 0;
        }

        Sprite(sf::Sprite* sprite) {
            sprites.push_back(sprite);
            length = 1;
            frame = 0;
        }

        void reset() {
            frame = 0;
        }

        sf::Sprite get() {
            sf::Sprite* out = sprites[frame];
            frame++;
            frame = frame % length;
            return *out;
        }
    };
}