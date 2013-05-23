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
  }

  void	Bombe::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
  }

  void	Bombe::draw(void)
  {
    //affichage du modele
    this->model_.draw(); 
  }
}
