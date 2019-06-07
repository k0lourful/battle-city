#include <Tank.h>

Tank::Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file)
    : mX(x), mY(y), mFile(file), mDx(0.f), mDy(0.f), mDir(0),
    mCurrentFrame(0.f), mSpeed(0.f), mWidth(width), mHeight(height) {

    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(26, 13, mWidth, mHeight));
    mSprite.setPosition(x, y);
}

void Tank::set_position(const int &x, const int &y) {
    coordinates.first = x;
    coordinates.second = y;
}

const sf::Sprite Tank::get_sprite() const { return mSprite; }

void Tank::animate(const sf::Time &time, const sf::Vector2f &movement) {
    mCurrentFrame += 0.00001f * time.asMicroseconds();
    if (mCurrentFrame >= 2)
        mCurrentFrame -= 2;

    if (movement.x > 0.01f)
        mSprite.setTextureRect(sf::IntRect(0 + 13 * (int)mCurrentFrame, 0, 13, 13));
    else if (movement.x < -0.01f)
        mSprite.setTextureRect(sf::IntRect(26 + 13 * (int)mCurrentFrame, 0, 13, 13));
    else if (movement.y > 0.01f)
        mSprite.setTextureRect(sf::IntRect(0 + 13 * (int)mCurrentFrame, 13, 13, 13));
    else if (movement.y < -0.01f)
        mSprite.setTextureRect(sf::IntRect(26 + 13 * (int)mCurrentFrame, 13, 13, 13));
}

//std::pair<int, int> Tank::get_position() const { return coordinates; }
