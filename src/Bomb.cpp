#include "Bomb.hpp"
#include <iostream>

namespace Bomb
{
  Bombe::Bombe(float const x, float const z, std::list<AObject*> *objects)
  {
    this->position_.x = x;
    this->position_.y = 0.0f;
    this->position_.z = z;
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
    this->timer_.play();
  }

  void	Bombe::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
    this->timer_.update();
    std::cout << this->timer_.getTotalElapsedTime() << std::endl;
    if (this->timer_.getTotalElapsedTime() >= 3)
      this->explose();
  }
  
  void	Bombe::draw(void)
  {if (over == true)
      {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glPopMatrix();
      }
    else
      {
  	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glTranslatef(this->position_.x, this->position_.y, this->position_.z);
	
	this->model_.draw();
	glPopMatrix();
      }
  }
  
  void	Bombe::explose()
  {
    over = true;
    this->timer_.pause();
    std::cout << "bomb" << std::endl;
    this->objects_->push_back(new Flamme(this->position_.x, this->position_.y, this->position_.z, this->objects_));
  }  
}

