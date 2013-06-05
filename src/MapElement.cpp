#include "MapElement.hpp"

namespace MapElement {

    Background::Background(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x;
        this->position_.y = 300.0f;
        this->position_.z = z;
        this->objects_ = objects;
        this->initialize();
    }

    Background::~Background() {
    }

    void Background::initialize(void) {
        this->texture_ = gdl::Image::load("assets/fond.png");
    }

    void Background::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    }

    void Background::draw(void) {
        texture_.bind();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(this->position_.x, this->position_.y, this->position_.z);

        glBegin(GL_QUADS);
        int size = 250;
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-size, -size, -size);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-size, -size, size);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(size, -size, size);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(size, -size, -size);
        /*glRotatef(this->camera_.getRotation().x +
                this->position_.x,
                this->camera_.getRotation().y +
                this->position_.y,
                this->camera_.getRotation().z +
                this->position_.z, 0.0f);*/
        glEnd();
        glPopMatrix();
    }

    Ground::Ground(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = GROUND;
        this->objects_ = objects;
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
       
        glEnd();
        glPopMatrix();
    }

    Wall::Wall(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = WALL;
        this->objects_ = objects;
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
	glPopMatrix();
    }

    Crate::Crate(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = CRATE;
        this->objects_ = objects;
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
        
        glEnd();
        glPopMatrix();
    }
}
