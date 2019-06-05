#pragma once
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Map : private sf::NonCopyable {
private:
	static const int HEIGHT_MAP = 28;
	static const int WIDTH_MAP = 32;
	sf::String TileMap[HEIGHT_MAP];
	sf::Texture mTexture;
	sf::Sprite mSprite;

public:
	Map();

    const char get_tile(const int &row, const int &column) const;
	void draw(sf::RenderWindow &window);
};
