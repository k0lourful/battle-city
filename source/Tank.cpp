#include <Tank.h>
#include <Map.h>

Tank::Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file)
    : mX(x), mY(y), mDx(0.f), mDy(0.f), mFile(file), mDir(0),
    mCurrentFrame(0.f), mSpeed(0.f), mWidth(width), mHeight(height) {

    mTexture.loadFromFile(mFile);
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(26, 13, mWidth, mHeight));
    mSprite.setPosition(x, y);
}

const sf::Sprite Tank::get_sprite() const { return mSprite; }

void Tank::animate(const float &time) {
    mCurrentFrame += 0.005f * time;
    if (mCurrentFrame >= 2)
        mCurrentFrame -= 2;

    if (mDx > 0.f)
        mSprite.setTextureRect(sf::IntRect(0 + 13 * (int)mCurrentFrame, 0, 13, 13));
    if (mDx < 0.f)
        mSprite.setTextureRect(sf::IntRect(26 + 13 * (int)mCurrentFrame, 0, 13, 13));
    if (mDy > 0.0f)
        mSprite.setTextureRect(sf::IntRect(0 + 13 * (int)mCurrentFrame, 13, 13, 13));
    if (mDy < 0.0f)
        mSprite.setTextureRect(sf::IntRect(26 + 13 * (int)mCurrentFrame, 13, 13, 13));
}

void Tank::update(const float &time, Map &map) {
    switch (mDir) {
        case 0:
            mDx = mSpeed;
            mDy = 0;
            break;

        case 1:
            mDx = -mSpeed;
            mDy = 0;
            break;

        case 2:
            mDx = 0;
            mDy = mSpeed;
            break;

        case 3:
            mDx = 0;
            mDy = -mSpeed;
            break;
    }
    mX += mDx * time;
    mY += mDy * time;

    mSpeed = 0;
    mSprite.setPosition(mX, mY);
    animate(time);
    map_interaction(map);
}

void Tank::map_interaction(Map &map) {
    for (int i = mY / 24; i < (mY + mHeight) / 24; ++i)
        for (int j = mX / 24; j < (mX + mWidth) / 24; ++j) {
            char tile = map.get_tile(i, j);

            if (tile >= '0' && tile <= '2') {
                if (mDy > 0.f)
                    mY = i * 24 - mHeight;

                if (mDy < 0.f)
                    mY = i * 24 + 24;

                if (mDx > 0.f)
                    mX = j * 24 - mWidth;

                if (mDx < 0.f)
                    mX = j * 24 + 24;
            }
        }

}
