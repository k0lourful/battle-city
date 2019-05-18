#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Tank : private sf::NonCopyable {
protected:
    float mX;
    float mY;
    float mWidth;
    float mHeight;

    enum Direction { Up, Down, Left, Right, } mDir;

    float mSpeed;

    sf::String mFile;
    sf::Texture mTexture;
    sf::Sprite mSprite;

    float mCurrentFrame;

public:
    explicit Tank(const float &x, const float &y, const float &width, const float &height, const sf::String &file);

    const sf::Sprite get_sprite() const;
    void set_sprite_position(const float &x, const float &y);
};
