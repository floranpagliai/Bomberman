#include "Primitive.hpp"

namespace Primitive {
  
  void Triangle::initialize(void) {
  }
  
  void Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input) {
  }
  
  void Triangle::draw(void) {
    
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.50f, 0.75f);
    glVertex3f(0.0f, 150.0f, 0.0f);
    glVertex3f(-150.0f, 0.0f, 0.0f);
    glVertex3f(150.0f, 00.0f, 0.0f);
    glEnd();
  }

  void Rectangle::initialize(void) {
  }
  
  void Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input) {
  }
  
  void Rectangle::draw(void) {
    
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.50f, 0.75f);
    glVertex3f(-150.0f, 100.0f, 0.0f);
    glVertex3f(-150.0f, -100.0f, 0.0f);
    glVertex3f(150.0f, -100.0f, 0.0f);
    glVertex3f(150.0f, 100.0f, 0.0f);
    glEnd();
  }
}
