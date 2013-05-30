//
// MapElement.cpp for MapElement.cpp in /home/cayrel_l//tek2/projet/bomber/Bomberman/src
//
// Made by lambert cayrel
// Login   <cayrel_l@epitech.net>
//
// Started on  Mon May 27 17:03:43 2013 lambert cayrel
// Last update Mon May 27 17:24:14 2013 lambert cayrel
//

#include "MapElement.hpp"

namespace MapElement {

    Ground::Ground(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->objects_ = objects;
        this->type_ = GROUND;
        this->initialize();
    }

    Ground::~Ground() {
    }

    void Ground::initialize(void) {
        this->texture_ = gdl::Image::load("assets/ground_sand.png");
    }

    void Ground::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    }

    void Ground::draw(void) {
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
        /*glRotatef(this->camera_.getRotation().x +
                this->position_.x,
                this->camera_.getRotation().y +
                this->position_.y,
                this->camera_.getRotation().z +
                this->position_.z, 0.0f);*/
        glEnd();
        glPopMatrix();
    }

    Wall::Wall(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->objects_ = objects;
        this->type_ = WALL;
        this->initialize();
    }

    Wall::~Wall() {
    }

    void Wall::initialize(void) {
        this->texture_ = gdl::Image::load("assets/ground_rock.png");
    }

    void Wall::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    }

    void Wall::draw(void) {
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
//        glRotatef(this->camera_.getRotation().x, 1.0f, 0.0f, 0.0f);
//        glRotatef(this->camera_.getRotation().y, 0.0f, 1.0f, 0.0f);
//        glRotatef(this->camera_.getRotation().z, 0.0f, 0.0f, 1.0f);

        glPopMatrix();
    }

    Crate::Crate(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->objects_ = objects;
        this->type_ = CRATE;
        this->initialize();
    }

    Crate::~Crate() {
    }

    void Crate::initialize(void) {
        this->texture_ = gdl::Image::load("assets/crate.png");
    }

    void Crate::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    }

    void Crate::draw(void) {
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
//        glRotatef(this->camera_.getRotation().x +
//                this->position_.x,
//                this->camera_.getRotation().y +
//                this->position_.y,
//                this->camera_.getRotation().z +
//                this->position_.z, 0.0f);
        glEnd();
        glPopMatrix();
    }
}
