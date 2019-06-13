#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
class Map;

class Bullet {
private:
    bool present; //is it shot?
    
    float mX, mY, mDx, mDy;
    int mDir;

    sf::Texture mTexture;
    sf::Sprite mSprite;

public:
    bool playerShot; //is it player's bullet?

    explicit Bullet(const float &x, const float &y, const bool &playerShot);

    void move(const sf::Int64 &time);
    void set_position(const float &x, const float &y);
    void update(Map &map, const sf::Int64 &time, float &x, const float &y, const int &dir);
    void map_interaction(Map &map);
};
