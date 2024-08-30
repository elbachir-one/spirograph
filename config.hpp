// config.hpp

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <SFML/Window/Keyboard.hpp>

const int INITIAL_WINDOW_WIDTH = 1920;
const int INITIAL_WINDOW_HEIGHT = 1080;
const float INITIAL_SPEED = 0.01f;
const float INITIAL_THICKNESS = 1.0f;
const float INITIAL_LENGTH_FACTOR = 1.5f;

// Key bindings
const sf::Keyboard::Key KEY_QUIT = sf::Keyboard::Q;
const sf::Keyboard::Key KEY_INCREASE_WIDTH = sf::Keyboard::Right;
const sf::Keyboard::Key KEY_DECREASE_WIDTH = sf::Keyboard::Left;
const sf::Keyboard::Key KEY_INCREASE_HEIGHT = sf::Keyboard::Up;
const sf::Keyboard::Key KEY_DECREASE_HEIGHT = sf::Keyboard::Down;
const sf::Keyboard::Key KEY_INCREASE_SPEED = sf::Keyboard::PageUp;
const sf::Keyboard::Key KEY_DECREASE_SPEED = sf::Keyboard::PageDown;
const sf::Keyboard::Key KEY_INCREASE_THICKNESS = sf::Keyboard::P;
const sf::Keyboard::Key KEY_DECREASE_THICKNESS = sf::Keyboard::N;
const sf::Keyboard::Key KEY_INCREASE_LENGTH = sf::Keyboard::K;
const sf::Keyboard::Key KEY_DECREASE_LENGTH = sf::Keyboard::L;

#endif
