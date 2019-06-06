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
    void map_interaction(sf::Vector2f &movement) {
        int x = mPlayer.get_position().first;
        int y = mPlayer.get_position().second;

        for(int i = (y - 24 * 2) / 24; i < (y - 24 * 2) / 24 + 1; ++i)
            for (int j = (x - 24 * 6) / 24; j < (x - 24 * 6) / 24 + 1; ++j) {
                char tile(map.get_tile(i, j));

                if (tile >= '0' && tile <= '2') {
                    if (mPlayer.movingUp || mPlayer.movingDown)
                        movement.y = 0.f;
                    if (mPlayer.movingLeft || mPlayer.movingRight)
                        movement.x = 0.f;
                }
            }
    }
};
