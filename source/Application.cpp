#include <SFML/Window/Event.hpp>
#include <Application.h>
#include <Map.h>

Application::Application()
    : mWindow(sf::VideoMode(768, 672), "Battle City"), gameOver(false) {

    float currentFrame(0.f);
    sf::Clock clock;

    while (mWindow.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
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

void Application::update(const float &time) {
    mPlayer.update(time, map);
}

void Application::render() {
    mWindow.clear();
    map.draw(mWindow);
    mWindow.draw(mPlayer.get_sprite());
    mWindow.display();
}


