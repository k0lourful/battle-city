#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Tank : private sf::NonCopyable  {
protected:
    float mX;
    float mY;
    int mWidth;
    int mHeight;
    
    float mCurrentFrame;

    sf::String mFile;
    sf::Texture mTexture;

public:
    explicit Tank(const float &x, const float &y, const int &width, const int &height, const sf::String &file);

    float mSpeed;
    bool movingUp;
    bool movingDown;
    bool movingLeft;
    bool movingRight;
    sf::Sprite mSprite;

    const sf::Sprite get_sprite() const;
    void set_sprite_position(const float &x, const float &y);
};
