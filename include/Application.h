#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Application : private sf::NonCopyable {
private:
    bool gameOver;
    float time;

    sf::RenderWindow mWindow;

public:
    Application();

    void update(const float &time);
    void render();
};
