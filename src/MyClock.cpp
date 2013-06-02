#include "MyClock.hpp"

MyClock::MyClock()
{

}

MyClock::~MyClock()
{

}

void	MyClock::initialize(void)
{
  this->timer_.play();
}

void	MyClock::update(gdl::GameClock const &, gdl::Input &)
{
  this->timer_.update();
  this->f_time = timer_.getTotalElapsedTime();
  this->s_time = float2string(f_time);
  
}


void	MyClock::draw(void)
{
  text_.setText(s_time);
  text_.setSize(20);//taille de la police d'écriture !
  text_.setPosition(0, 500);
  
  //dimension of the OpenGl component
  int w = 1024;
  int h = 700;
  
  
  //Top left viewport : Viewport 1                                     //reset the view on the viewport  
  //  glViewport(0, h/2, w/2, h/2);
  //text_.draw();  
  //glLoadIdentity();                                            //reset the view on the viewport
  //gluLookAt(0.0, 0.0, this->position_.z, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //front view
  //drawScene(glDrawable, quadric);    //draws the object of the scene
  text_.draw();
  /*
  glTranslatef(0.0f, -1.0f, 0.0f);
  glPushMatrix();
  glRotatef(0.0f, 1.0f, 0.0f, 0.f);
  glTranslatef(-1.5f,0.0f,0.0f);
  glRotatef(90.f, 0.0f, 1.0f, 0.0f);
  glPopMatrix();  
  */
}

std::string	MyClock::float2string(float f)
{
  std::ostringstream	os;
  os << f;
  return os.str();
}
