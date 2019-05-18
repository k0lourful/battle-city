#include <SFML/Window/Event.hpp>
#include <Application.h>

Application::Application()
    : mWindow(sf::VideoMode(1280,720), "Battle City"), gameOver(false) {

    srand(std::time(NULL));
    mWindow.setFramerateLimit(60);

    sf::Clock clock;
    while (mWindow.isOpen()) {
        time = clock.getElapsedTime().asMicroseconds() / 800;
        clock.restart();

        sf::Event event;
        while (mWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                mWindow.close();
        }

        if (!gameOver)
            update(time);

        render();
    }
}

void Application::update(const float &time) {}

void Application::render() {
    mWindow.clear();
    mWindow.display();
}
