#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <Map.h>
#include <Player.h>
#include <Enemy.h>
#include <Base.h>

class Application : private sf::NonCopyable {
private:
    bool gameOver;

    sf::RenderWindow mWindow;
    Base mBase;
    Map map;
    Player mPlayer;
    Enemy *packOfEnemies;

public:
    Application();

    void process_events();
    void update(const sf::Int64 &time);
    void render();
};
