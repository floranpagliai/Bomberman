#include "MyGame.hpp"


//création window, add objects, initialize objects
void	MyGame::initialize(void)
{
  window_.setTitle("Chevre");
  window_.setHeight(700);
  window_.setWidth(1024);
  window_.create();
  camera_.initialize();

  //objects_.push_back(new Bomb::Bombe());
  //objects_.push_back(new Primitive::Rectangle());
  //objects_.push_back(new Primitive::Triangle());
  //objects_.push_back(new Object::Cube());
  //objects_.push_back(new Object::Pyramide());
  //Model::Player *pl = new Model::Player(); 
  objects_.push_back(new Model::Player(1000.0f, 1000.0f, &objects_));
  
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();
}

//update objects
void	MyGame::update(void)
{
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->update(gameClock_, input_);
  camera_.update(gameClock_, input_);
}

//dump buffers, call method object draw and display rendenring in the window
void	MyGame::draw(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.0f, 102.0f, 0.0f, 1.0f);
  glClearDepth(1.0f);
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->draw();
  this->window_.display();
}

//free all
void	MyGame::unload(void)
{
  /*
    doit liberer la mémoire lorsque la fenêtre est fermée !!
   */
}
