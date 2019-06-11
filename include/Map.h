#pragma once
#include <SFML/System/String.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map {
private:
    static const int HEIGHT_MAP = 28;
    static const int WIDTH_MAP = 32;

    sf::String *TileMap;
    sf::Texture mTexture;
    sf::Sprite mSprite;

public:
    Map();

    const char get_tile(const int &i, const int &j) { return TileMap[i][j]; }
    void draw(sf::RenderWindow &window);
};
