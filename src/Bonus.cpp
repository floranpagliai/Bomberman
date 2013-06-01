/*
 * File:   Bonus.cpp
 * Author: floran
 *
 * Created on 1 juin 2013, 01:05
 */

#include "Bonus.hpp"

namespace Bonus {

    FireUp::FireUp(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x;
        this->position_.y = BLOCK_SIZE;
        this->position_.z = z;
        this->type_ = FIREUP;
        this->dirAnim_ = 0;
        this->objects_ = objects;
        this->initialize();
    }

    FireUp::~FireUp() {

    }

    void FireUp::initialize(void) {
        this->texture_ = gdl::Image::load("assets/bombUp.png");
    }

    void FireUp::update(gdl::GameClock const & gameClock, gdl::Input & input) {
        if (this->position_.y >= BLOCK_SIZE && dirAnim_ == 0)
            this->position_.y += 2.0f;
        if (this->position_.y == BLOCK_SIZE && dirAnim_ == 1)
            dirAnim_ = 0;
        if (this->position_.y == BLOCK_SIZE + 100 && dirAnim_ == 0)
            dirAnim_ = 1;
        if (this->position_.y <= BLOCK_SIZE + 100 && dirAnim_ == 1)
            this->position_.y -= 2.0f;
    }

    void FireUp::draw(void) {
        texture_.bind();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(this->position_.x, this->position_.y, this->position_.z);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glEnd();
        glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
        glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
        glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);

        glPopMatrix();
    }

    PowerUp::PowerUp(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x;
        this->position_.y = BLOCK_SIZE;
        this->position_.z = z;
        this->type_ = POWERUP;
        this->dirAnim_ = 0;
        this->objects_ = objects;
        this->initialize();
    }

    PowerUp::~PowerUp() {

    }

    void PowerUp::initialize(void) {
        this->texture_ = gdl::Image::load("assets/powerUp.png");
    }

    void PowerUp::update(gdl::GameClock const & gameClock, gdl::Input & input) {
        if (this->position_.y >= BLOCK_SIZE && dirAnim_ == 0)
            this->position_.y += 2.0f;
        if (this->position_.y == BLOCK_SIZE && dirAnim_ == 1)
            dirAnim_ = 0;
        if (this->position_.y == BLOCK_SIZE + 100 && dirAnim_ == 0)
            dirAnim_ = 1;
        if (this->position_.y <= BLOCK_SIZE + 100 && dirAnim_ == 1)
            this->position_.y -= 2.0f;
    }

    void PowerUp::draw(void) {
        texture_.bind();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(this->position_.x, this->position_.y, this->position_.z);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glEnd();
        glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
        glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
        glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);

        glPopMatrix();
    }

    SpeedUp::SpeedUp(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x;
        this->position_.y = BLOCK_SIZE;
        this->position_.z = z;
        this->type_ = SPEEDUP;
        this->dirAnim_ = 0;
        this->objects_ = objects;
        this->initialize();
    }

    SpeedUp::~SpeedUp() {

    }

    void SpeedUp::initialize(void) {
        this->texture_ = gdl::Image::load("assets/speedUp.png");
    }

    void SpeedUp::update(gdl::GameClock const & gameClock, gdl::Input & input) {
        if (this->position_.y >= BLOCK_SIZE && dirAnim_ == 0)
            this->position_.y += 2.0f;
        if (this->position_.y == BLOCK_SIZE && dirAnim_ == 1)
            dirAnim_ = 0;
        if (this->position_.y == BLOCK_SIZE + 100 && dirAnim_ == 0)
            dirAnim_ = 1;
        if (this->position_.y <= BLOCK_SIZE + 100 && dirAnim_ == 1)
            this->position_.y -= 2.0f;
    }

    void SpeedUp::draw(void) {
        texture_.bind();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(this->position_.x, this->position_.y, this->position_.z);
        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, -BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, BONUS_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(BONUS_SIZE, BONUS_SIZE, -BONUS_SIZE);

        glEnd();
        glRotatef(this->rotation_.x, 1.0f, 0.0f, 0.0f);
        glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);
        glRotatef(this->rotation_.z, 0.0f, 0.0f, 1.0f);

        glPopMatrix();
    }
}
