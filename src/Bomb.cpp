#include "Bomb.hpp"

namespace Bomb
{
  void	Bombe::initialize(void)
  {
    //charge le modele
    this->model_ = gdl::Model::load("assets/bomb.fbx");
  }

  void	Bombe::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
    model_.set_default_model_color(gdl::Color(255, 0, 0));
  }

  void	Bombe::draw(void)
  {
    //affichage du modele
    this->model_.draw();
  }
}
