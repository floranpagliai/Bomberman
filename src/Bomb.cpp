#include "Bomb.hpp"

namespace Bomb
{
<<<<<<< HEAD
<<<<<<< HEAD
  /*  Bombe::Bombe(float const x, float const z)
  {
    this->position_.x = x;
    this->position_.y = 0.0f;
    this->position_.z = z;
    this->initialize();
    }*/
=======
  Bombe::Bombe(float const x, float const y, std::list<AObject*> objects)
=======
  Bombe::Bombe(float const x, float const y, std::list<AObject*> *objects)
>>>>>>> Resolution bug Bomb
  {
    this->position_.x = x;
    this->position_.y = y;
    this->position_.z = 0.0f;
    this->objects_ = objects;
    this->initialize();
  }

  Bombe::~Bombe()
  {

  }
>>>>>>> commit pour flo avec Bug creation Bomb

  void	Bombe::initialize(void)
  {
    //charge le modele
    this->model_ = gdl::Model::load("assets/bomb.fbx");
  }
  
  void	Bombe::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
  }

  void	Bombe::draw(void)
  {
    //affichage du modele
    //  this->model_.draw(); 
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    gdl::Model::Begin();
    this->model_.draw();
    gdl::Model::End();
    glPopMatrix();
  }
}
