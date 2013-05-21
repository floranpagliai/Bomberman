#ifndef __OBJECTS_HPP__
#define __OBJECTS_HPP__

#include "AObject.hpp"
#include "Vector3f.hpp"
#include "Image.hpp"
#include "GameClock.hpp"
#include "Input.hpp"

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
