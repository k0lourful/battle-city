#include <SFML/Window/Keyboard.hpp>
#include <Player.h>

Player::Player()
    : Tank(200, 200, 12, 12, "battle-city-src/media/playerSprites.png") {
    mSprite.setScale(3, 3);
    mSpeed = 30.f;
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
