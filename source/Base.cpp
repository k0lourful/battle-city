#include <Base.h>

Base::Base()
    : life(true) {
    mTexture.loadFromFile("battle-city-src/media/baseSprite.png");
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, 48, 48));
    mSprite.setPosition(336, 600);
}
