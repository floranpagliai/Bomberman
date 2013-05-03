#include "MyGame.hpp"

void	MyGame::initialize(void) {
  window_.create();
  camera_.initialize();
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

void	MyGame::update(void) {
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
  camera_.update(gameClock_, input_);
}

void MyGame::draw(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
  this->window_.display();
}
void MyGame::unload(void) {

}
