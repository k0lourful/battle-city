#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <utility>
class Map;

class Tank : private sf::NonCopyable  {
protected:
    
    float mX, mY, mWidth, mHeight, mDx, mDy, mSpeed;
    int mDir;
    float mCurrentFrame;

    sf::String mFile;
    sf::Texture mTexture;

public:
    explicit Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file);

    sf::Sprite mSprite;

    void animate(const float &time);
    const sf::Sprite get_sprite() const;

    virtual void update(const float &time, Map &map);
    void map_interaction(Map &map);
};
