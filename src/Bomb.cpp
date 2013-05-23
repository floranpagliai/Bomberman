#include "Bomb.hpp"

namespace Bomb
{
  /*  Bombe::Bombe(float const x, float const z)
  {
    this->position_.x = x;
    this->position_.y = 0.0f;
    this->position_.z = z;
    this->initialize();
    }*/

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
