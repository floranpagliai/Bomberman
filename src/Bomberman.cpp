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
    // Destruction des ressources.
    //delete this->odel_;
    }*/

  void Bomberman::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    /// Si une animation est en cours, nous la mettons a jour
    this->model_.update(gameClock);
    model_.set_default_model_color(gdl::Color(255,0,0));
    //model_.set_anim_speed("Take 001", 1); //pour changer la vitesse quand il court
    //model_.infos(); // pour avoir les infos sur le personnage

    /// Joue l’animation portant le nom "Take 001" quand on appuie sur la touche "p"
    if (input.isKeyDown(gdl::Keys::Up) == true)
      this->model_.play("Take 001");
    else if (input.isKeyDown(gdl::Keys::Down) == true)
      this->model_.play("Take 001", 4);
    else if (input.isKeyDown(gdl::Keys::Left) == true)
      this->model_.play("Take 001");
    else if (input.isKeyDown(gdl::Keys::Right) == true)
      {
	this->rotation_.y = ((int)rotation_.y + 1) % 360;      
	this->model_.play("Take 001");
      }
  }
  void Bomberman::draw(void)
  {
    /// Affichage du modele
    this->model_.draw();
  }
}
