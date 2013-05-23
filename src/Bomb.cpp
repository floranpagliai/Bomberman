#include "Bomb.hpp"

namespace Bomb
{
  Bombe::Bombe(float const x, float const y, std::list<AObject*> *objects)
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

  void	Bombe::initialize(void)
  {
    //charge le modele
    this->model_ = gdl::Model::load("assets/bomb.fbx");
    int		x = this->position_.x;
    int		z = this->position_.z;

    if (x % (BLOCK_SIZE * 2) > BLOCK_SIZE)
      x += (BLOCK_SIZE * 2 - (x % (BLOCK_SIZE * 2)));
    else
      x -= x % (BLOCK_SIZE * 2);
    if (z % (BLOCK_SIZE * 2) > BLOCK_SIZE)
      z += (BLOCK_SIZE * 2 - (z % (BLOCK_SIZE * 2)));
    else
      z -= z % (BLOCK_SIZE * 2);
    this->position_.x = x;
    this->position_.z = z;
  }
  
  void	Bombe::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
  }

  void	Bombe::draw(void)
  {
    //affichage du modele
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    gdl::Model::Begin();
    this->model_.draw();
    gdl::Model::End();
    glPopMatrix();
  }
}
