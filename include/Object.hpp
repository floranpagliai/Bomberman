#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "AObject.hpp"
#include "Vector3f.hpp"
#include "Image.hpp"
#include "GameClock.hpp"
#include "Input.hpp"
#include "MyGame.hpp"
namespace Object
{
  class Cube : public AObject
  {
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
  };
  
  class Pyramide : public AObject
  {
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
  };
}

#endif
