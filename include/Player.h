#include <SFML/System/NonCopyable.hpp>
#include <Tank.h>

class Player : public Tank {
public:
    Player();

    void move(const sf::Event & key);
};
