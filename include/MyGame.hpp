#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include <GL/gl.h>
#include <GL/glu.h>
#include "Game.hpp"
#include "Model.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Object.hpp"
#include "Input.hpp"

#include <cstdlib>
#include <list>

#include "AObject.hpp"
#include "Camera.hpp"
#include "Primitive.hpp"
#include "Player.hpp"
#include "Bomb.hpp"

class MyGame : public gdl::Game
{
private:
  Camera		camera_;
  std::list<AObject*>	objects_;

public:
  void	initialize(void);
  void	update(void);
  void	draw(void);
  void	unload(void);
};

#endif
