#pragma once
#include <SFML/Window/Keyboard.hpp>
#include <Tank.h>

class Player : public Tank {
public:
    Player();

    void update(const float &time, Map &map);
    void move();
};
