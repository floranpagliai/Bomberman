#include "Display.hpp"

namespace Display {

  Timer::Timer(std::list<AObject *> *objects) {
    this->position_.x = -200.0f;
    this->position_.y = 200.0f;
    this->position_.z = -5100.0f;
    this->objects_ = objects;
    this->C_timer_.play();
    this->initialize();
  }

    Timer::~Timer() {
    }

    void Timer::initialize(void) {
        this->texture_ = gdl::Image::load("assets/clock.png");
    }

    void Timer::update(gdl::GameClock const &, gdl::Input &) {
        this->C_timer_.update();
        this->f_time_ = C_timer_.getTotalElapsedTime();
        this->s_time_ = float2string(f_time_);
    }

    void Timer::draw(void) {
        texture_.bind();
        glEnable(GL_TEXTURE_2D);
        glPushMatrix();
        glTranslatef(this->position_.x, this->position_.y, this->position_.z);

        glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-DISPLAY_SIZE, -DISPLAY_SIZE, -DISPLAY_SIZE);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-DISPLAY_SIZE, -DISPLAY_SIZE, DISPLAY_SIZE);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(DISPLAY_SIZE, -DISPLAY_SIZE, DISPLAY_SIZE);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(DISPLAY_SIZE, -DISPLAY_SIZE, -DISPLAY_SIZE);

        glEnd();
        glPopMatrix();
        camera_.setPosition(this->camera_.getPosition().x + 1.f, camera_.getPosition().y, camera_.getPosition().z);

        T_time_.setText(s_time_);
        T_time_.setSize(18);
        T_time_.setPosition(500, 10);
        T_time_.draw();

        camera_.setPosition(camera_.getPosition().x - 1.f, camera_.getPosition().y, (camera_.getPosition().z));
    }

    std::string Timer::float2string(float f) {
        std::ostringstream os;

        if (f >= 10.00 && f <= 100.00)
            os << std::setprecision(2) << f;
        else if (f < 10)
            os << std::setprecision(1) << f;
        else
            os << std::setprecision(3) << f;
        return os.str();
    }

    DisplayPlayer::DisplayPlayer(Bomberman *pl) {
        this->p_player = pl;
    }

    DisplayPlayer::~DisplayPlayer() {
    }

    void DisplayPlayer::initialize(void) {
    }

    void DisplayPlayer::update(gdl::GameClock const &, gdl::Input &) {
        this->i_bomb = this->p_player->getAmmoStock();
        this->s_bomb = intToStr(this->i_bomb);

        this->i_speed_ = this->p_player->getSpeed();
        this->s_speed_ = intToStr(this->i_speed_);

        this->i_power_ = this->p_player->getPower();
        this->s_power_ = intToStr(this->i_power_);
    }

    void DisplayPlayer::draw(void) {
        camera__.setPosition(this->camera__.getPosition().x, camera__.getPosition().y, camera__.getPosition().z + 1.0f);

        if (this->p_player->getId() == 1) {
            nb_Bomb_.setText("\tPlayer 1\n\nBombes: " + s_bomb);
            nb_Bomb_.setSize(20); //taille de la police d'écriture !
            nb_Bomb_.setPosition(10, 100);
            nb_Bomb_.draw();

            speed_.setText("Speed: " + s_speed_);
            speed_.setSize(20); //taille de la police d'écriture !
            speed_.setPosition(10, 170);
            speed_.draw();

            power_.setText("Power: " + s_power_);
            power_.setSize(20); //taille de la police d'écriture !
            power_.setPosition(10, 200);
            power_.draw();
        } else if (this->p_player->getId() == 2) {

            nb_Bomb_.setText("\tPlayer 2\n\nBombes: " + s_bomb);
            nb_Bomb_.setSize(20); //taille de la police d'écriture !
            nb_Bomb_.setPosition(910, 100);
            nb_Bomb_.draw();

            speed_.setText("Speed: " + s_speed_);
            speed_.setSize(20); //taille de la police d'écriture !
            speed_.setPosition(910, 170);
            speed_.draw();

            power_.setText("Power: " + s_power_);
            power_.setSize(20); //taille de la police d'écriture !
            power_.setPosition(910, 200);
            power_.draw();
        }
        camera__.setPosition(camera__.getPosition().x, camera__.getPosition().y, (camera__.getPosition().z - 1.0f));
    }

    std::string DisplayPlayer::intToStr(int nb) {
        std::ostringstream os;

        os << nb;
        return os.str();
    }

  ResultFinal::ResultFinal(int id_play) {
    this->position_.x = 0;
    this->position_.y = 300;
    this->position_.z = 0;
    this->id_player = id_play;
    this->initialize();
  }

  ResultFinal::~ResultFinal() {

  }

  void	ResultFinal::initialize(void) {
    if (this->id_player == 1)
      this->texture_ = gdl::Image::load("assets/menu/winj1.png");
    else if (this->id_player == 2)
      this->texture_ = gdl::Image::load("assets/menu/winj2.png");
    else
      this->texture_ = gdl::Image::load("assets/menu/bomberover.png");
  }

  void	ResultFinal::update(gdl::GameClock const &, gdl::Input &) {

  }

  void	ResultFinal::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);

    texture_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    glViewport(0, 0, WINDOW_WIDHT, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDHT, 0, WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, WINDOW_HEIGHT, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(WINDOW_WIDHT, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(WINDOW_WIDHT, WINDOW_HEIGHT, 0.0f);

    glEnd();
    glPopMatrix();
  }
}

