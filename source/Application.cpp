#include <SFML/Window/Event.hpp>
#include <Application.h>

Application::Application()
    : mWindow(sf::VideoMode(768, 672), "Battle City"), gameOver(false) {
    packOfEnemies = new Enemy[1]{Enemy(52,30)};

    float currentFrame(0.f);
    sf::Clock clock;

    while (mWindow.isOpen()) {
        sf::Int64 time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        process_events();
        update(time);
        render();
    }
}

void Application::process_events() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Application::update(const sf::Int64 &time) {
    const bool collision = mPlayer.get_sprite().getGlobalBounds().intersects(packOfEnemies[0].get_sprite().getGlobalBounds());
    mPlayer.update(time, map, collision);
    packOfEnemies[0].update(time, map, collision);
}

void Application::render() {
    mWindow.clear();
    map.draw(mWindow);
    mWindow.draw(mPlayer.get_sprite());
    if(mPlayer.bullet.present) mWindow.draw(mPlayer.bullet.mSprite);

    mWindow.draw(packOfEnemies[0].get_sprite());

    mWindow.draw(mBase.get_sprite());
    mWindow.display();
}


