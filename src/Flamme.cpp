#include "Flamme.hpp"

Flamme::Flamme(float const x, float const z, int const power, int dir, std::list<AObject*> *objects) {
    this-> position_.x = x;
    this-> position_.y = 0.0f;
    this->position_.z = z;
    this->type_ = FLAMME;
    this->power_ = power;
    this->objects_ = objects;
    isExpand_ = false;
    dir_ = dir;
    this->checkPropagation();
    this->initialize();
}

Flamme::~Flamme() {
}

void Flamme::initialize() {
    this->texture_ = gdl::Image::load("assets/flamme.jpg");
    this->timer_.play();
}

void Flamme::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    this->timer_.update();
    if (this->isExpand_ == false) {

        this->propagate();
        this->isExpand_ = true;
    }
    if (this->timer_.getTotalElapsedTime() >= TIMER_FLAMME)
        this->isOver = true;
}

void Flamme::draw() {
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

    glEnd();
    glPopMatrix();
}

void Flamme::propagate(void) const {
    if (dir_ == 1 && this->power_ > 0)
        this->objects_->push_front(new Flamme(this->position_.x + BLOCK_SIZE * 2, this->position_.z, (this->power_ - 1), 1, this->objects_));
    else if (dir_ == 2 && this->power_ > 0)
        this->objects_->push_front(new Flamme(this->position_.x - BLOCK_SIZE * 2, this->position_.z, (this->power_ - 1), 2, this->objects_));
    else if (dir_ == 3 && this->power_ > 0)
        this->objects_->push_front(new Flamme(this->position_.x, this->position_.z + BLOCK_SIZE * 2, (this->power_ - 1), 3, this->objects_));
    else if (dir_ == 4 && this->power_ > 0)
        this->objects_->push_front(new Flamme(this->position_.x, this->position_.z - BLOCK_SIZE * 2, (this->power_ - 1), 4, this->objects_));
}

void Flamme::checkPropagation(void) {
    std::list<AObject *>::iterator it = this->objects_->begin();
    for (std::list<AObject *>::iterator it = this->objects_->begin(); it != this->objects_->end() && this->isOver == false; it++) {
        if (((*it)->getType() == PLAYER || (*it)->getType() == CRATE) && this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) == true) {
            if ((*it)->getType() == CRATE) {
                this->power_ = 0;
                this->popBonus();
            }
            (*it)->setIsOver();
            //break;

        } else if (((*it)->getType() == WALL) && this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) == true) {
            this->power_ = 0;
            break;
        }
    }
}

void Flamme::popBonus(void) {
    int value = rand() % 6 + 1;
    if (value == 1 || value == 2 || value == 3 || (value == 4 && rand()% 2 == 1))
        this->objects_->push_front(new Bonus(this->position_.x, this->position_.z, (eBonusType) value, this->objects_));
}