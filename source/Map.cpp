#include "Map.h"
using sf::IntRect;

Map::Map() {
	TileMap[0] =  "00000000000000000000000000000000";
	TileMap[1] =  "00                          0000";
	TileMap[2] =  "00                          0000";
	TileMap[3] =  "00  11  11  11  11  11  11  0000";
	TileMap[4] =  "00  11  11  11  11  11  11  0000";
	TileMap[5] =  "00  11  11  11  11  11  11  0000";
	TileMap[6] =  "00  11  11  11  11  11  11  0000";
	TileMap[7] =  "00  11  11  112211  11  11  0000";
	TileMap[8] =  "00  11  11  112211  11  11  0000";
	TileMap[9] =  "00  11  11  11  11  11  11  0000";
	TileMap[10] = "00  11  11          11  11  0000";
	TileMap[11] = "00  11  11          11  11  0000";
	TileMap[12] = "00          11  11          0000";
	TileMap[13] = "00          11  11          0000";
	TileMap[14] = "0011  1111          1111  110000";
	TileMap[15] = "0022  1111          1111  220000";
	TileMap[16] = "00          11  11          0000";
	TileMap[17] = "00          111111          0000";
	TileMap[18] = "00  11  11  111111  11  11  0000";
	TileMap[19] = "00  11  11  11  11  11  11  0000";
	TileMap[20] = "00  11  11  11  11  11  11  0000";
	TileMap[21] = "00  11  11  11  11  11  11  0000";
	TileMap[22] = "00  11  11          11  11  0000";
	TileMap[23] = "00  11  11          11  11  0000";
	TileMap[24] = "00  11  11   1111   11  11  0000";
	TileMap[25] = "00           1  1           0000";
	TileMap[26] = "00           1  1           0000";
	TileMap[27] = "00000000000000000000000000000000";

	mTexture.loadFromFile("battle-city-src/media/groundSprites.png");
	mSprite.setTexture(mTexture);
	mSprite.setScale(1.5f, 1.5f);
}

const char Map::get_tile(const int &row, const int &column) const { return TileMap[row][column]; }

void Map::draw(sf::RenderWindow &window) {
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++) {
			if (TileMap[i][j] == ' ')  mSprite.setTextureRect(IntRect(0, 0, 16, 16));
			if (TileMap[i][j] == '0') mSprite.setTextureRect(IntRect(48, 0, 16, 16));
			if (TileMap[i][j] == '1')  mSprite.setTextureRect(IntRect(16, 0, 16, 16));
			if (TileMap[i][j] == '2') mSprite.setTextureRect(IntRect(32, 0, 16, 16));

			mSprite.setPosition(j * 24, i * 24);

			window.draw(mSprite);
		}
}
