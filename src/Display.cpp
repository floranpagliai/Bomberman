#include "Display.hpp"

namespace Display {
  
  Timer::Timer(std::list<AObject *> *objects)
  {
    this->position_.x = 100;
    this->position_.y = 1.0f;
    this->position_.z = 100;
    this->objects_ = objects;
    this->C_timer_.play();
  }
  
  Timer::~Timer(){
  }
  
  void	Timer::initialize(void){
    this->texture_ = gdl::Image::load("assets/clock.png");
  }
  
  void	Timer::update(gdl::GameClock const &, gdl::Input &)
  {
    this->C_timer_.update();
    this->f_time_ = C_timer_.getTotalElapsedTime();
    this->s_time_ = float2string(f_time_); 
  }
  
  
  void	Timer::draw(void)
  {
    camera_.setPosition(this->camera_.getPosition().x, camera_.getPosition().y, camera_.getPosition().z+50.f);
    
    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);

    glEnd();
    glPopMatrix();

    T_time_.setText( "Time : " + s_time_);
    T_time_.setSize(20);//taille de la police d'écriture !
    T_time_.setPosition(500, 10);
    T_time_.draw();

    camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, (camera_.getPosition().z-50.f));
  }
  
  std::string	Timer::float2string(float f)
  {
    std::ostringstream	os;
    
    if (f >= 10.00 && f <= 100.00)
      os << std::setprecision(2) << f;
    else if (f < 10)
      os << std::setprecision(1) << f;
    else
      os << std::setprecision(3) << f;
    return os.str();
  }

  DisplayPlayer::DisplayPlayer(Bomberman *pl) {
    this->p_player = pl;
  }

  DisplayPlayer::~DisplayPlayer() {
  }
  
  void	DisplayPlayer::initialize(void) {
  }

  void	DisplayPlayer::update(gdl::GameClock const &, gdl::Input &) {
    this->i_bomb = this->p_player->getAmmoStock();
    this->s_bomb = intToStr(this->i_bomb);
  
    this->i_speed_ = this->p_player->getSpeed();
    this->s_speed_ = intToStr(this->i_speed_);
    
    this->i_power_ = this->p_player->getPower();
    this->s_power_ = intToStr(this->i_power_);
}
  
  void	DisplayPlayer::draw(void) {
    camera__.setPosition(this->camera__.getPosition().x, camera__.getPosition().y, camera__.getPosition().z+50.f);
    
    if (this->p_player->getId() == 0) {
      nb_Bomb_.setText( "Bombes: " + s_bomb);
      nb_Bomb_.setSize(20);//taille de la police d'écriture !
      nb_Bomb_.setPosition(10, 170);
      nb_Bomb_.draw();
      
      score_.setText( "Player 1\n\nScore : 0");
      score_.setSize(20);//taille de la police d'écriture !
      score_.setPosition(10, 100);
      score_.draw();

      speed_.setText( "Speed: " + s_speed_);
      speed_.setSize(20);//taille de la police d'écriture !
      speed_.setPosition(10, 200);
      speed_.draw();

      power_.setText( "Power: " + s_power_);
      power_.setSize(20);//taille de la police d'écriture !
      power_.setPosition(10, 230);
      power_.draw();
    }
    else if (this->p_player->getId() == 1) {
      
      nb_Bomb_.setText( "Bombes: " + s_bomb);
      nb_Bomb_.setSize(20);//taille de la police d'écriture !
      nb_Bomb_.setPosition(910, 170);
      nb_Bomb_.draw();
      
      score_.setText( "Player2\n\nScore : 0");
      score_.setSize(20);//taille de la police d'écriture !
      score_.setPosition(910, 100);
      score_.draw();

      speed_.setText( "Speed: " + s_speed_);
      speed_.setSize(20);//taille de la police d'écriture !
      speed_.setPosition(910, 200);
      speed_.draw();

      power_.setText( "Power: " + s_power_);
      power_.setSize(20);//taille de la police d'écriture !
      power_.setPosition(910, 230);
      power_.draw();
    }
    camera__.setPosition(camera__.getPosition().x, camera__.getPosition().y, (camera__.getPosition().z-50.f));
  }

  std::string	DisplayPlayer::intToStr(int nb)
  {
    std::ostringstream	os;
    
    os << nb;
    return os.str();
  }
}

