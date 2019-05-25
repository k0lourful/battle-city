#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <Player.h>

Player::Player()
    : Tank(200, 200, 12, 12, "battle-city-src/media/playerSprites.png") {
    mSprite.setScale(3, 3);
    mSpeed = 5.f;
}

void Player::move() {
    
}
