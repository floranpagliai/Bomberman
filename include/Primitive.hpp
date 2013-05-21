#include <GL/gl.h>
#include <GL/glu.h>
#include "Input.hpp"

#include "AObject.hpp"
#include "Vector3f.hpp"
#include "Objects.hpp"
namespace Primitive
{
  class Triangle : public AObject
  {
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
  };
  
  class Rectangle : public AObject
  {
    void initialize(void);
    void update(gdl::GameClock const &, gdl::Input &);
    void draw(void);
  };
}
