#include "Flamme.hpp"

Flamme::Flamme(float const x, float const y, float const z, int const power, std::list<AObject*> *objects) {
    this-> position_.x = x;
    this-> position_.y = 0.0f;
    this->position_.z = z;
    this->objects_ = objects;
    this->power_ = power;
    this->initialize();
}

Flamme::~Flamme() {

}

void Flamme::initialize() {
    this->texture_ = gdl::Image::load("assets/flamme.jpg");
    this->timer_.play();
}

void Flamme::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    //this->texture_.update(gameClock);
    this->destroyObjects();
    if (this->isOver == false) {
        this->timer_.update();
        this->expand();
        if (this->timer_.getTotalElapsedTime() >= 0.5)
            this->isOver = true;
    }
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

void Flamme::expand() {
    if (this->power_ > 0) {
        this->objects_->push_back(new Flamme(this->position_.x + BLOCK_SIZE * 2, this->position_.y, this->position_.z, this->power_ - 1, this->objects_));
        this->objects_->push_back(new Flamme(this->position_.x - BLOCK_SIZE * 2, this->position_.y, this->position_.z, this->power_ - 1, this->objects_));
        this->objects_->push_back(new Flamme(this->position_.x, this->position_.y, this->position_.z + BLOCK_SIZE * 2, this->power_ - 1, this->objects_));
        this->objects_->push_back(new Flamme(this->position_.x, this->position_.y, this->position_.z - BLOCK_SIZE * 2, this->power_ - 1, this->objects_));
    }
}

void Flamme::setDirection(e_direction direction) {
    direction_ = direction;
}

e_direction Flamme::getDirection() const {

}

void Flamme::explose() {
    this->isOver = true;
    this->timer_.pause();
    //expand();
}

void Flamme::destroyObjects(void) {
    std::list<AObject *>::iterator it = this->objects_->begin();

    for (; it != this->objects_->end() && this->isOver == false; it++) {
        if (((*it)->getType() == CRATE)
                && this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) == true) {
            this->isOver = true;
            delete *it;
            objects_->erase(it);
        } else if (((*it)->getType() == PLAYER || (*it)->getType() == WALL) &&
                this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) == true) {
            if ((*it)->getType() != WALL) {
                delete *it;
                objects_->erase(it);
            } else {
                this->isOver = true;
            }
            break;

        }
    }
}