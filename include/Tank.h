#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
//#include <utility>

class Tank : private sf::NonCopyable  {
protected:
    float mX, mY, mDx, mDy, mHeight, mWidth, mSpeed;
    int mDir;
    //std::pair<float, float> coordinates;
    float mCurrentFrame;

    sf::String mFile;
    sf::Texture mTexture;

public:
    explicit Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file);

    //bool movingUp;
    //bool movingDown;
    //bool movingLeft;
    //bool movingRight;
    sf::Sprite mSprite;

    void animate(const sf::Time &time, const sf::Vector2f &movement);
    const sf::Sprite get_sprite() const;
    void set_position(const int &x, const int &y);
    //std::pair<int, int> get_position() const;
};
