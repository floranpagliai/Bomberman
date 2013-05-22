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
    //Bombe();
    //~Bombe();
    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);
  private:
    gdl::Model	model_;
  };
}
#endif
