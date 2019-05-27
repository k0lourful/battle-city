#include <SFML/Window/Event.hpp>
#include <Application.h>

Application::Application()
    : mWindow(sf::VideoMode(960, 720), "Battle City"), gameOver(false) {

    const sf::Time timePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    sf::Clock clock;
    while (mWindow.isOpen()) {
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            process_events();
            update(timePerFrame);
        }
        render();
    }
}

void Application::process_events() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::KeyPressed:
                mPlayer.handle_input(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                mPlayer.handle_input(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;
        }
    }
}

void Application::update(const sf::Time &timePerFrame) {
    sf::Vector2f movement(0.f, 0.f);
    
    if (mPlayer.movingUp)
        movement.y -= mPlayer.mSpeed;
    if (mPlayer.movingDown)
        movement.y += mPlayer.mSpeed;
    if (mPlayer.movingLeft)
        movement.x -= mPlayer.mSpeed;
    if (mPlayer.movingRight)
        movement.x += mPlayer.mSpeed;

    mPlayer.mSprite.move(movement * timePerFrame.asSeconds());
}

void Application::render() {
    mWindow.clear();
    mWindow.draw(mPlayer.get_sprite());
    mWindow.display();
}
