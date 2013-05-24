#include "Player.hpp"

namespace Model
{
  Player::Player(float const x, float const y, std::list<AObject*> *objects)
  {
    this->position_.x = x;
    this->position_.y = y;
    this->position_.z = 5.0f;
    this->objects_ = objects;
    this->initialize();
  }

  Player::~Player()
  {
    
  }

  void Player::initialize(void)
  {
    /// Charge le modele
    this->model_ = gdl::Model::load("assets/marvin.fbx");
    this->isPush = false;
    model_.set_default_model_color(gdl::Color(255,0,0));
    speed_ = 0;
    model_.set_anim_speed("Take 001", 1 + this->speed_); //pour changer la vitesse quand il court
    model_.cut_animation(this->model_, "Take 001", 40, 50, "Run");
    model_.cut_animation(this->model_, "Take 001", 0, 0, "Stop");
  }

  void Player::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
    this->move(input);
    this->putBomb(input);
  }

  void	Player::draw(void)
  {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);

    this->model_.draw();
    glPopMatrix();
  }

	void	Player::move(gdl::Input &input)
	{
		if (input.isKeyDown(gdl::Keys::Up) == true)
      {
        this->rotation_.y = 180;
        this->position_.y += 25.0f + speed_ * 2.0f;
	this->model_.play("Run");
      }
    else if (input.isKeyDown(gdl::Keys::Down) == true)
      {
        this->rotation_.y = 0;
        this->position_.y -= 25.0f + speed_ * 2.0f;
        this->model_.play("Run");
      }
    else if (input.isKeyDown(gdl::Keys::Left) == true)
    {
      this->rotation_.y = -90;
      this->position_.x -= 25.0f + speed_ * 2.0f;
      this->model_.play("Run");
    }
    else if (input.isKeyDown(gdl::Keys::Right) == true)
      {
        this->rotation_.y = 90;
        this->position_.x += 25.0f + speed_ * 2.0f;
	this->model_.play("Run");
      }
    else
        this->model_.play("Stop");
	}
	
  void	Player::putBomb(gdl::Input &input)
  {
  	
    if (input.isKeyDown(gdl::Keys::B) == true && this->isPush == false)
      {
		this->objects_->push_front(new Bomb::Bombe(this->position_.x, this->position_.y, this->objects_));
		this->isPush = true;
      }
      else
      	this->isPush = false;
  }

  int	Player::getAmmo() const
  {
    return ammo_;
  }

  int	Player::getPower() const
  {
    return power_;
  }

  int	Player::getSpeed() const
  {
    return speed_;
  }

  void	Player::ammoUp()
  {
    ammo_ += 1;
  }

  void	Player::powerUp()
  {
    power_ += 1;
  }

  void	Player::speedUp()
  {
    speed_ += 1;
  }
}
