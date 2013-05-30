#ifndef __FLAMME_HPP__
#define __FLAMME_HPP__

#include <GL/gl.h>
#include <GL/glu.h>
#include <iostream>

#include "AObject.hpp"
#include "Model.hpp"
#include "GameClock.hpp"
#include "Input.hpp"
#include "Camera.hpp"


enum	e_direction
  {
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3
  };

class Flamme : public AObject
{
private:
  int		power_;
  gdl::Clock	timer_;
  gdl::Image	texture_;
  e_direction	direction_;
  std::list<AObject*>	*objects_;
  gdl::Model	model_;
  //  bool		over;
  
public:
  Flamme(float const x, float const y, float const z, std::list<AObject*> *objects);
  ~Flamme();
  
  void		initialize(void);
  void		update(gdl::GameClock const &, gdl::Input &);
  void		draw(void);  
  void		expand(void);
  void		setDirection(e_direction);
  e_direction	getDirection() const;
  void		explose();
};

#endif
