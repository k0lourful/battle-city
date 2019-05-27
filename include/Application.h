#include <SFML/Graphics/RenderWindow.hpp>
#include <Player.h>

class Application : private sf::NonCopyable {
private:
    bool gameOver;

    sf::RenderWindow mWindow;

    Player mPlayer;

public:
    Application();

    void process_events();
    void update(const sf::Time &deltaTime);
    void render();
};
