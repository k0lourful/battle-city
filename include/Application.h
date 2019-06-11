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
    void update(const float &time);
    void render();
};
