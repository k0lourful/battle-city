#include <Tank.h>

Tank::Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file)
    : mX(x), mY(y), mFile(file), movingUp(false), movingDown(false), movingLeft(false), movingRight(false),
    mSpeed(0), mCurrentFrame(0), mWidth(width), mHeight(height) {

    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 1, mWidth, mHeight));
    mSprite.setPosition(mX, mY);
}

void Tank::set_sprite_position(const float &x, const float &y) {
    mX = x;
    mY = y;
    mSprite.setPosition(mX, mY);
}

const sf::Sprite Tank::get_sprite() const { return mSprite; }

void Tank::animate(const sf::Time &time, const sf::Vector2f &movement) {
    mCurrentFrame += 0.00001f * time.asMicroseconds();
    if (mCurrentFrame >= 2)
        mCurrentFrame -= 2;

    if (movement.x > 0.01f)
        mSprite.setTextureRect(sf::IntRect(96 + 16 * (int)mCurrentFrame, 0, 13, 13));
    else if (movement.x < -0.01f)
        mSprite.setTextureRect(sf::IntRect(33 + 16 * (int)mCurrentFrame, 0, 13, 13));
    else if (movement.y > 0.01f)
        mSprite.setTextureRect(sf::IntRect(64 + 16 * (int)mCurrentFrame, 0, 13, 13));
    else if (movement.y < -0.01f)
        mSprite.setTextureRect(sf::IntRect(16 * (int)mCurrentFrame, 1, 13, 13));
}
