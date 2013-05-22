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
    model_.cut_animation(this->model_, "Take 001", 40, 50, "Run");
    model_.cut_animation(this->model_, "Take 001", 0, 0, "Stop");

    if (input.isKeyDown(gdl::Keys::Up) == true)
      {
        this->rotation_.y = 180;
        this->position_.y += 45.0f;
	this->model_.play("Run");
      }
    else if (input.isKeyDown(gdl::Keys::Down) == true)
      {
        this->rotation_.y = 0;
        this->position_.y -= 45.0f;
        this->model_.play("Run");
      }
    else if (input.isKeyDown(gdl::Keys::Left) == true)
    {
      this->rotation_.y = -90;
      this->position_.x -= 45.0f;
      this->model_.play("Run");
    }
    else if (input.isKeyDown(gdl::Keys::Right) == true)
      {
        this->rotation_.y = 90;
        this->position_.x += 45.0f;
	this->model_.play("Run");
      }
    else
        this->model_.play("Stop");
  }

  void Bomberman::draw(void)
  {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
    gdl::Model::Begin();
    this->model_.draw();
    gdl::Model::End();
    glPopMatrix();
  }
}
