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
#include <iostream>
#include <fstream>

#include "AObject.hpp"
#include "Bomb.hpp"
#include "Camera.hpp"
#include "Map.hpp"
#include "MapElement.hpp"
#include "Parser.hpp"
#include "Player.hpp"


class MyGame : public gdl::Game
{
private:
  Camera		camera_;
  std::list<AObject*>	objects_;

public:
  virtual void	initialize(void);
  virtual void	update(void);
  virtual void	draw(void);
  virtual void	unload(void);

  void openMap(const char *name);
};

#endif
