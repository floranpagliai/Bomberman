#ifndef __MYGAME_HPP_
#define __MYGAME_HPP_

#include <cstdlib>
#include <list>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Game.hpp"
#include "AObject.hpp"
#include "Camera.hpp"

class MyGame : public gdl::Game {
private:
  Camera	camera_;
  std::list<AObject*>	objects_;

public:
  void	initialize(void);
  void	update(void);
  void	draw(void);
  void	unload(void);
};

#endif
