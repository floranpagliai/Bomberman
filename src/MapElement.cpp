#include "MapElement.hpp"

namespace MapElement {

    Background::Background(float const x, float const z, eMapTheme theme, std::list<AObject*> *objects) {
        this->position_.x = x;
        this->position_.y = 1.0f;
        this->position_.z = z;
        this->theme_ = theme;
        this->objects_ = objects;
        this->initialize();
    }

    Background::~Background() {
    }

    void Background::initialize(void) {
        if (this->theme_ == PLAINE)
            this->texture_ = gdl::Image::load("assets/plaine/fond.png");
        else if (this->theme_ == USINE)
            this->texture_ = gdl::Image::load("assets/usine/fond.png");
        else if (this->theme_ == POLENORD)
            this->texture_ = gdl::Image::load("assets/polenord/fond.png");
    }

    void Background::update(gdl::GameClock const & gameClock, gdl::Input & input) {
    }

    void Background::draw(void) {
        texture_.bind();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(this->position_.x, this->position_.y, this->position_.z);

        glBegin(GL_QUADS);
        int size = 9800;

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-size, -size, -size);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-size, -size, size);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(size, -size, size);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(size, -size, -size);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(size, size, -size);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(size, -size, -size);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-size, -size, -size);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-size, size, -size);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(size, size, size);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(size, -size, size);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(size, -size, -size);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(size, size, -size);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-size, size, size);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-size, -size, size);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-size, -size, -size);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-size, size, -size);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-size, size, -size);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-size, size, size);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(size, size, size);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(size, size, -size);
        
        glEnd();
        glPopMatrix();
    }

    Ground::Ground(float const x, float const z, eMapTheme theme, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = GROUND;
        this->theme_ = theme;
        this->objects_ = objects;
        this->initialize();
    }

    Ground::~Ground() {
    }

    void Ground::initialize(void) {
        if (this->theme_ == PLAINE)
            this->texture_ = gdl::Image::load("assets/plaine/ground.png");
        else if (this->theme_ == USINE)
            this->texture_ = gdl::Image::load("assets/usine/ground.png");
        else if (this->theme_ == POLENORD)
            this->texture_ = gdl::Image::load("assets/polenord/ground.png");
        else
            this->texture_ = gdl::Image::load("assets/ground.png");
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

    Wall::Wall(float const x, float const z, eMapTheme theme, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = WALL;
        this->theme_ = theme;
        this->objects_ = objects;
        this->initialize();
    }

    Wall::~Wall() {
    }

    void Wall::initialize(void) {
        if (this->theme_ == PLAINE)
            this->texture_ = gdl::Image::load("assets/plaine/wall.png");
        else if (this->theme_ == USINE)
            this->texture_ = gdl::Image::load("assets/usine/wall.png");
        else if (this->theme_ == POLENORD)
            this->texture_ = gdl::Image::load("assets/polenord/wall.png");
        else
            this->texture_ = gdl::Image::load("assets/wall.png");
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

    Crate::Crate(float const x, float const z, eMapTheme theme, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = CRATE;
        this->theme_ = theme;
        this->objects_ = objects;
        this->initialize();
    }

    Crate::~Crate() {
    }

    void Crate::initialize(void) {
        if (this->theme_ == PLAINE)
            this->texture_ = gdl::Image::load("assets/plaine/crate.png");
        else if (this->theme_ == USINE)
            this->texture_ = gdl::Image::load("assets/usine/crate.png");
        else if (this->theme_ == POLENORD)
            this->texture_ = gdl::Image::load("assets/polenord/crate.png");
        else
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
