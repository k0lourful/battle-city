#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
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

        std::cout << x << " " << y << std::endl;

        for(int i = (y - 24) / 24; i < (y - 24 + 13) / 24; ++i)
            for (int j = (x - 24 * 2) / 24; j < (x - 24 * 2 + 13) / 24; ++j) {
                char tile(map.get_tile(i, j));
                std::cout << tile << std::endl;

                if (tile == '0' || tile == '1' || tile == '2') {
                    if (mPlayer.movingUp)
                        movement.y = 0.f;
                    if (mPlayer.movingDown)
                        movement.y = 0.f;
                    if (mPlayer.movingLeft)
                        movement.x = 0.f;
                    if (mPlayer.movingRight)
                        movement.x = 0.f;
                }
            }
    }
};
