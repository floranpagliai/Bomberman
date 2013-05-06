#include <GL/gl.h>
#include <GL/glu.h>

#include "AObject.hpp"
#include "Input.hpp"
#include "Vector3f.hpp"

namespace Primitive {
class Triangle : public AObject {
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
