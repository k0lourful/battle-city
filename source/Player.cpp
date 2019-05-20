#include <SFML/Window/Keyboard.hpp>
#include <Player.h>

Player::Player()
    : Tank(200, 200, 12, 12, "Media/playerSprites.png") {
    mSpeed = 0.1f;
}

void Player::move() {
    switch (sf::Keyboard::isKeyPressed()) {
        case sf::Keyboard::Up :
            mSprite.move(0, -mSpeed);
            break;

}
