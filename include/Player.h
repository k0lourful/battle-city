#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <Tank.h>

class Player : public Tank {
public:
    Player();

    void handle_input(const sf::Keyboard::Key &key, const bool &isPressed);
};
