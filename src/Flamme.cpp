#include "Flamme.hpp"

Flamme::Flamme(float const x, float const y, float const z, std::list<AObject*> *objects)
{
  std::cout<< "1" << std::endl;
  this-> position_.x = x;
  this-> position_.y = 0.0f;
  this->position_.z = z;
  this->objects_ = objects;
  this->initialize();
}

Flamme::~Flamme()
{

}

void	Flamme::initialize()
{
  std::cout<< "2" << std::endl;
  this->texture_ = gdl::Image::load("assets/flamme.jpg");
    std::cout<< "3" << std::endl;
  this->timer_.play();
  std::cout<< "4" << std::endl;
}

void	Flamme::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  std::cout<< "5" << std::endl;
  //this->texture_.update(gameClock);
    std::cout<< "6" << std::endl;
  this->timer_.update();
   std::cout<< "7" << std::endl;
  std::cout << this->timer_.getTotalElapsedTime() << std::endl;
  if (this->timer_.getTotalElapsedTime() >= 10)
    this->explose();
}

void	Flamme::draw()
{
  /*if (over == true)
    {
      glMatrixMode(GL_MODELVIEW);
      glPushMatrix();
      glPopMatrix();
    }
  else
  {*/
      texture_.bind();
      glEnable(GL_TEXTURE_2D);
      glPushMatrix();
      glTranslatef(this->position_.x, this->position_.y, this->position_.z);
      glBegin(GL_QUADS);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(BLOCK_SIZE, BLOCK_SIZE, -BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE, BLOCK_SIZE, -BLOCK_SIZE);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(BLOCK_SIZE, BLOCK_SIZE, -BLOCK_SIZE);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE, -BLOCK_SIZE, -BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE, BLOCK_SIZE, -BLOCK_SIZE);

      glTexCoord2f(0.0f, 0.0f);
      glVertex3f(-BLOCK_SIZE, BLOCK_SIZE, -BLOCK_SIZE);
      glTexCoord2f(0.0f, 1.0f);
      glVertex3f(-BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(1.0f, 1.0f);
      glVertex3f(BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE);
      glTexCoord2f(1.0f, 0.0f);
      glVertex3f(BLOCK_SIZE, BLOCK_SIZE, -BLOCK_SIZE);
      /* glRotatef(this->camera_.getRotation().x +
                this->position_.x,
                this->camera_.getRotation().y +
                this->position_.y,
                this->camera_.getRotation().z +
                this->position_.z, 0.0f);*/
      glEnd();
      glPopMatrix();
      // }
}

void	Flamme::expand()
{

}

void		Flamme::setDirection(e_direction direction)
{
  direction_ = direction;
}

e_direction	Flamme::getDirection() const
{

}

void		Flamme::explose()
{
    std::cout<< "8" << std::endl;
  over = true;
  this->timer_.pause();
}
