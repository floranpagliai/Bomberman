#include "Bomberman.hpp"

///////////////////////////////////////////////////////////////////////////////
/// Definition de la classe Bomberman
////////////////////////////////////////////////////////////////////////////////
namespace Model
{
  void Bomberman::initialize(void)
  {
    /// Charge le modele
    this->model_ = gdl::Model::load("assets/marvin.fbx");
  }

  /*void Bomberman::~Bomberman(void)
  {
    /// Destruction des ressources.
    //delete this->odel_;
    }*/

  void Bomberman::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    /// Si une animation est en cours, nous la mettons a jour
    this->model_.update(gameClock);
    model_.set_default_model_color(gdl::Color(255,255,0));
    /// Joue l’animation portant le nom "Take 001" quand on appuie sur la touche "p"
    if (input.isKeyDown(gdl::Keys::P) == true)
      this->model_.play("Take 001");
  }
  void Bomberman::draw(void)
  {
    /// Affichage du modele
    this->model_.draw();
  }
}
