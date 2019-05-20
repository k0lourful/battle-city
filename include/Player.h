#include <SFML/System/NonCopyable.hpp>
#include <Tank.h>

class Player : private Tank, private sf::NonCopyable {
public:
    Player();

    void move();
};
