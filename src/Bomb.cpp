#include "Bomb.hpp"

Bombe::Bombe(float const x, float const z, int const power, std::list<AObject*> *objects, Player *pl) {
  this->position_.x = x;
  this->position_.y = 0.0f;
  this->position_.z = z;
  this->type_ = BOMB;
  this->power_ = power;
  this->objects_ = objects;
  this->pl_ = pl;
  this->initialize();
}

Bombe::~Bombe() {
}

void Bombe::initialize(void) {
    this->model_ = gdl::Model::load("assets/bomb.fbx");
    int x = this->position_.x;
    int z = this->position_.z;
    if (x > 0) {
        if (x % (BLOCK_SIZE * 2) > BLOCK_SIZE)
            x += (BLOCK_SIZE * 2 - (x % (BLOCK_SIZE * 2)));
        else
            x -= x % (BLOCK_SIZE * 2);
    } else {
        if (-x % (BLOCK_SIZE * 2) > BLOCK_SIZE)
            x -= (BLOCK_SIZE * 2 + (x % (BLOCK_SIZE * 2)));
        else
            x -= x % (BLOCK_SIZE * 2);
    }
    if (z > 0) {
        if (z % (BLOCK_SIZE * 2) > BLOCK_SIZE)
            z += (BLOCK_SIZE * 2 - (z % (BLOCK_SIZE * 2)));
        else
            z -= z % (BLOCK_SIZE * 2);
    } else {
        if (-z % (BLOCK_SIZE * 2) > BLOCK_SIZE)
            z -= (BLOCK_SIZE * 2 + (z % (BLOCK_SIZE * 2)));
        else
            z -= z % (BLOCK_SIZE * 2);
    }
    this->position_.x = x;
    this->position_.z = z;
    this->timer_.play();
}

void Bombe::update(gdl::GameClock const & gameClock, gdl::Input & input) {
  this->model_.update(gameClock);
  this->timer_.update();
  if (this->timer_.getTotalElapsedTime() >= TIMER_BOMB)
    this->explose();
  for (std::list<AObject *>::iterator it = this->objects_->begin(); it != this->objects_->end() && this->isOver == false; it++) {
    if (((*it)->getType() == FLAMME) && this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) == true) {
      this->explose();
    }
  }
}

void Bombe::draw(void) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(this->position_.x, this->position_.y, this->position_.z);

    this->model_.draw();
    glPopMatrix();
}

void Bombe::explose() {
  this->pl_->setAmmo(1);  
  explosion = new sf::Music();
  explosion->OpenFromFile("sound/explosion.wav");
  explosion->Play();
  this->timer_.pause();
  this->isOver = true;
  this->objects_->push_front(new Flamme(this->position_.x, this->position_.z, 0, 1, this->objects_));
  this->objects_->push_front(new Flamme(this->position_.x + BLOCK_SIZE * 2, this->position_.z, this->power_, 1, this->objects_));
  this->objects_->push_front(new Flamme(this->position_.x - BLOCK_SIZE * 2, this->position_.z, this->power_, 2, this->objects_));
  this->objects_->push_front(new Flamme(this->position_.x, this->position_.z + BLOCK_SIZE * 2, this->power_, 3, this->objects_));
  this->objects_->push_front(new Flamme(this->position_.x, this->position_.z - BLOCK_SIZE * 2, this->power_, 4, this->objects_));
}

