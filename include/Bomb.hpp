#ifndef __BOMB_HPP__
#define __BOMB_HPP__

#include "AObject.hpp"
#include "Model.hpp"
#include "GameClock.hpp"
#include "Input.hpp"

namespace Bomb
{
  class Bombe : public AObject
  {
  public:
<<<<<<< HEAD
<<<<<<< HEAD
    //    Bombe();
    //~Bombe();
=======
    Bombe(float const x, float const y, std::list<AObject *> objects);
=======
    Bombe(float const x, float const y, std::list<AObject*> *);
>>>>>>> Resolution bug Bomb
    ~Bombe();
>>>>>>> commit pour flo avec Bug creation Bomb
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
  private:
    gdl::Model	model_;
    std::list<AObject*>	*objects_;
    
  };
}
#endif
