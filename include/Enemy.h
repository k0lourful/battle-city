#pragma once
#include <Tank.h>
class Enemy : public Tank {
public:
    Enemy(const float &x, const float &y);
    Enemy(const Enemy &copy) : Enemy(copy.mX, copy.mY){}

    void move();
};
