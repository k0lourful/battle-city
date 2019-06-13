#include <Map.h>

Map::Map() {
    TileMap = new sf::String[HEIGHT_MAP] {
        "00000000000000000000000000000000",
        "00                          0000",
        "00                          0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11  112211  11  11  0000",
        "00  11  11  112211  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11          11  11  0000",
        "00  11  11          11  11  0000",
        "00          11  11          0000",
        "00          11  11          0000",
        "0011  1111          1111  110000",
        "0022  1111          1111  220000",
        "00          11  11          0000",
        "00          111111          0000",
        "00  11  11  111111  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11  11  11  11  11  0000",
        "00  11  11          11  11  0000",
        "00  11  11          11  11  0000",
        "00  11  11   1111   11  11  0000",
        "00           1  1           0000",
        "00           1  1           0000",
        "00000000000000000000000000000000",
    };

    mTexture.loadFromFile("battle-city-src/media/groundSprites.png");
    mTexture.setSmooth(true);
    mSprite.setTexture(mTexture);
}

void Map::break_wall(const int &i, const int &j) {
    TileMap[i][j] = ' ';
}

void Map::draw(sf::RenderWindow &window) {
    for (int i(0); i < HEIGHT_MAP; i++)
        for (int j(0); j < WIDTH_MAP; j++) {
            switch (TileMap[i][j]) {
                case ' ':
                    mSprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
                    break;

                case '0':
                    mSprite.setTextureRect(sf::IntRect(72, 0, 24, 24));
                    break;

                case '1':
                    mSprite.setTextureRect(sf::IntRect(24, 0, 24, 24));
                    break;

                case '2':
                    mSprite.setTextureRect(sf::IntRect(48, 0, 24, 24));
                    break;
            }

            mSprite.setPosition(j * 24, i * 24);
            window.draw(mSprite);
        }
}
