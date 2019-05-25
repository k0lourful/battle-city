#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <Player.h>

class Application : private sf::NonCopyable {
private:
    bool gameOver;
    float time;

    sf::RenderWindow mWindow;

    Player player;

public:
    Application();

    void update(const float &time);
    void render();
};
