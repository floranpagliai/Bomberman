#include "MyClock.hpp"

MyClock::MyClock()
{
  this->timer_.play();
}

MyClock::~MyClock(){
}

void	MyClock::initialize(void){
}

void	MyClock::update(gdl::GameClock const &, gdl::Input &)
{
  this->timer_.update();
  this->f_time = timer_.getTotalElapsedTime();
  this->s_time = float2string(f_time);

}


void	MyClock::draw(void)
{
  camera_.setPosition(this->camera_.getPosition().x, camera_.getPosition().y, camera_.getPosition().z+50.f);

  text_.setText( "Time : " + s_time);
  text_.setSize(20);//taille de la police d'écriture !
  text_.setPosition(10, 100);
  text_.draw();

  scoreP1_.setText( "Score P1: 0");
  scoreP1_.setSize(20);//taille de la police d'écriture !
  scoreP1_.setPosition(10, 170);
  scoreP1_.draw();

  scoreP2_.setText( "Score P2: 0");
  scoreP2_.setSize(20);//taille de la police d'écriture !
  scoreP2_.setPosition(10, 240);
  scoreP2_.draw();

  camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, (camera_.getPosition().z-50.f));
}

std::string	MyClock::float2string(float f)
{
  std::ostringstream	os;

  if (f > 10.00 && f < 100.00)
    os << std::setprecision(4) << f;
  else if (f < 10)
    os << std::setprecision(3) << f;
  else
    os << std::setprecision(5) << f;
  return os.str();
}
