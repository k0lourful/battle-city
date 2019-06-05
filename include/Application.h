#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <Player.h>
#include <Map.h>

class Application : private sf::NonCopyable {
private:
    bool gameOver;

    sf::RenderWindow mWindow;
    Map map;
    Player mPlayer;

public:
    Application();

    void process_events();
    void update(const sf::Time &deltaTime);
    void render();
    void map_interaction() {
        int x = mPlayer.get_position().first;
        int y = mPlayer.get_position().second;

        for(int i = y / 24; i < (y + 28) / 24; ++i)
            for (int j = x / 24; j < (x + 32) / 24; ++j) {
                char tile(map.get_tile(i, j));

                if (tile >= '0' && tile <= '2') {
                    if (mPlayer.movingDown)
                        mPlayer.set_position(x, i * 32 - 28);
                    if (mPlayer.movingUp)
                        mPlayer.set_position(x, i * 32 + 32);
                    if (mPlayer.movingRight)
                        mPlayer.set_position(j * 32 - 32, y);
                    if (mPlayer.movingLeft)
                        mPlayer.set_position(j * 32 + 32, y);
                }
            }
    }
};
