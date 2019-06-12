#include <Enemy.h>

Enemy::Enemy(const float &x, const float &y)
    : Tank(x, y, 39, 39, "battle-city-src/media/enemySprites.png"), timeBeforeMoving(0.f) {
}

void Enemy::move(const sf::Int64 &time) {
    mSpeed = 0.1f;
    timeBeforeMoving += time;

    if (timeBeforeMoving > 1500) {
        mDir = rand() % 4;
        timeBeforeMoving = 0.f;
    }
    
}

void Enemy::update(const sf::Int64 &time, Map &map) {
    move(time);

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
