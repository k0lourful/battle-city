#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Base : private sf::NonCopyable {
private:
    bool destroyed;

    sf::Texture mTexture;
    sf::Sprite mSprite;

public:
    Base();

    sf::Sprite get_sprite() const { return mSprite; }
};
