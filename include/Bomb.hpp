#ifndef __BOMB_HPP__
#define __BOMB_HPP__

#include <SFML/Audio.hpp>
#include "Player.h"
#include "AObject.hpp"
#include "Flamme.hpp"

#define TIMER_BOMB 3
class Player;
class Bombe : public AObject{
private:
  std::list<AObject*> *objects_;
  gdl::Model	model_;
  gdl::Clock	timer_;
  int		power_;
  Player	*pl_;

public:
  Bombe(float const, float const, int const, std::list<AObject*> *, Player *);
    ~Bombe();
  
  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);
  void draw(void);
  
  void explose();
    
  sf::Music	*explosion;
};

#endif
