#include <SFML/Window/Keyboard.hpp>
#include <Player.h>

Player::Player()
    : Tank(200, 200, 13, 13, "battle-city-src/media/playerSprites.png") {
    mSprite.setScale(4, 4);
    mSpeed = 100.f;
}

void Player::handle_input(const sf::Keyboard::Key &key, const bool &isPressed) {
    if (key == sf::Keyboard::Up)
        movingUp = isPressed;
    else if (key == sf::Keyboard::Down)
        movingDown = isPressed;
    else if (key == sf::Keyboard::Left)
        movingLeft = isPressed;
    else if (key == sf::Keyboard::Right)
        movingRight = isPressed;
}
