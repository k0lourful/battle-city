#include <Tank.h>

Tank::Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file)
    : mX(x), mY(y), mFile(file), movingUp(false), movingDown(false), movingLeft(false), movingRight(false),
    mSpeed(0), mCurrentFrame(0), mWidth(width), mHeight(height) {

    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, mWidth, mHeight));
    mSprite.setPosition(mX, mY);
}

void Tank::set_sprite_position(const float &x, const float &y) {
    mX = x;
    mY = y;
    mSprite.setPosition(mX, mY);
}

const sf::Sprite Tank::get_sprite() const { return mSprite; }
