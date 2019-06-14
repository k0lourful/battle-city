#include <Bullet.h>
#include <Map.h>

Bullet::Bullet(const float &x, const float &y, const bool &playerShot)
    : present(false), mX(x), mY(y), mDir(0), mDx(0.f), mDy(0.f) {

    this->playerShot = playerShot;

    mTexture.loadFromFile("battle-city-src/media/bulletSprite.png");
    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0, 0, 9, 12));
    mSprite.setPosition(x, y);
}

void Bullet::set_position(const float &x, const float &y) {
    mX = x;
    mY = y;
}

void Bullet::move(const sf::Int64 &time) {
    switch (mDir) {
        case 0:
            mDx = 0.2f;
            mDy = 0;
            break;

        case 1:
            mDx = -0.2f;
            mDy = 0;
            break;

        case 2:
            mDx = 0;
            mDy = 0.2f;
            break;

        case 3:
            mDx = 0;
            mDy = -0.2f;
            break;
    }

    mX += mDx * time;
    mY += mDy * time;
}

void Bullet::update(Map &map, const sf::Int64 &time, float &x, const float &y, const int &dir) {
    mDir = dir;

    if (present) {
        move(time);
        map_interaction(map);
    }
    else {

    }
}

void Bullet::map_interaction(Map &map) {
    for (int i = mY / 24; i < (mY + 12) / 24; ++i)
        for (int j = mX / 24; j < (mX + 9) / 24; ++j) {
            char tile = map.get_tile(i, j);

            if (tile == '0' || tile == '2')
                present = false;

            if (tile == '1') {
                map.break_wall(i, j);
                present = false;
            }
        }
}
