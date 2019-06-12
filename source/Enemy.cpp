#include <Enemy.h>
#include <random>

Enemy::Enemy(const float &x, const float &y)
    : Tank(x, y, 39, 39, "battle-city-src/media/enemySprites.png") {
}

void Enemy::move() {
    mDir = rand() % 4;
    mSpeed = 0.1f;
}
