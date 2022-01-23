#pragma once

#include "IAecs.hpp"
#include <string>
#include <vector>
#include <map>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

// Represents the application as a whole.
// Stores Worlds, Sprites, Audio, etc...

namespace IA::ECS {
    struct App {
        std::map<std::string, World*> worlds;
        World* activeWorld;
        sf::RenderWindow* window;
        bool activeWorldSet = false; // if the active world has been assigned
        std::map<std::string, Sprite> sprites; // Stores sprites
        std::map<std::string, sf::Texture> textures; // Stores textures, not used but need to be stored somewhere

        // Blank Constructor
        App() {
            window = new sf::RenderWindow(sf::VideoMode(1500, 900), "Application");
        }

        // Window details constructor
        App(int width = 800, int height = 600, std::string title = "Application") {
            window = new sf::RenderWindow(sf::VideoMode(width, height), title);
        }

        // returns false if the app is no longer running
        bool update() {
            activeWorld->update();

            sf::Event event;
            while (window->pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window->close();
                    break;
                
                default:
                    break;
                }
            }
        }

        void add_world(std::string name, World* world) {
            world->app = this;
            worlds[name] = world;
            if (!activeWorldSet) {
                activeWorldSet = true;
                activeWorld = world;
            }
        }

        // Load sprite from files. Filename is without extension (expects .png). Will also check a subdirectory with the same name if it exists
        // if length > 1, then it will look for multiple files that start with the filename in the following format:
        // Filename_x.png - xth image in the sequence
        // Filename_x,y,z.png - xth, yth, and zth image in the sequence
        // Filename_x-y.png - xth to yth image in the sequence inclusive
        // Commas and ranges can be combined
        // TODO: implement this system
        void load_sprite(std::string filename, std::string name, int length = 1) {
            if (length == 1) {
                sf::Texture texture;
                texture.loadFromFile(SPRITES_DIR + filename + ".png");
                sf::Sprite* sfmlSprite = new sf::Sprite(texture);
                Sprite sprite(sfmlSprite);
                sprites[name] = sprite;
                textures[name] = texture;
            }
        }
    };
}