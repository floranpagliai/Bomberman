#ifndef __BOMB_HPP__
#define __BOMB_HPP__

#include <pthread.h>

#include "AObject.hpp"
#include "Player.h"
#include "Flamme.hpp"

#define TIMER_BOMB 3

class Player;

class Bombe : public AObject {
private:
    std::list<AObject*> *objects_;
    gdl::Model model_;
    gdl::Clock timer_;
    Player *pl_;
    int power_;


public:
    Bombe(float const, float const, int const, std::list<AObject*> *, Player *);
    virtual ~Bombe();

    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);

    void explose(void);

    sf::Music *explosion;
};

#endif
