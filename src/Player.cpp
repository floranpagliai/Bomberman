#include "Player.hpp"

namespace Model {

    Player::Player(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->ammo_ = 0;
        this->speed_ = 0;
        this->objects_ = objects;
        this->isPush_ = false;
        this->initialize();
    }

    Player::~Player() {

    }

    void Player::initialize(void) {
        /// Charge le modele
        this->model_ = gdl::Model::load("assets/marvin.fbx");
        model_.set_default_model_color(gdl::Color(255, 0, 0));
        model_.set_anim_speed("Take 001", 1 + this->speed_); //pour changer la vitesse quand il court
        model_.cut_animation(this->model_, "Take 001", 0, 30, "StartRun");
        model_.cut_animation(this->model_, "Take 001", 35, 53, "Run");
        model_.cut_animation(this->model_, "Take 001", 57, 120, "EndRun");
        model_.cut_animation(this->model_, "Take 001", 0, 0, "Stop");
    }

    void Player::update(gdl::GameClock const & gameClock, gdl::Input & input) {
        this->model_.update(gameClock);
        this->checkMove(input);
        this->putBomb(input);
    }

    void Player::draw(void) {
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();

        glTranslatef(this->position_.x, this->position_.y, this->position_.z);
        glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);

        this->model_.draw();
        glPopMatrix();
    }

    void Player::checkMove(gdl::Input &input) {
        std::list<AObject*>::iterator itb;
        if (input.isKeyDown(gdl::Keys::Up) == true || input.isKeyDown(gdl::Keys::Down) == true
                || input.isKeyDown(gdl::Keys::Left) == true || input.isKeyDown(gdl::Keys::Right) == true) {
            move(input);
        } else {
            this->model_.play("Stop");
        }
        if (input.isKeyDown(gdl::Keys::S) == true) {
            this->speedUp();
        }
        if (input.isKeyDown(gdl::Keys::A) == true) {

            this->ammoUp();
        }
    }

    void Player::move(gdl::Input &input) {

        if (input.isKeyDown(gdl::Keys::Up) == true) {
            this->rotation_.y = 180;
            this->position_.z -= 25.0f + speed_ * 8.0f;
            this->model_.play("Run");
        } else if (input.isKeyDown(gdl::Keys::Down) == true) {
            this->rotation_.y = 0;
            this->position_.z += 25.0f + speed_ * 8.0f;
            this->model_.play("Run");
        } else if (input.isKeyDown(gdl::Keys::Left) == true) {
            this->rotation_.y = -90;
            this->position_.x -= 25.0f + speed_ * 8.0f;
            this->model_.play("Run");
        } else if (input.isKeyDown(gdl::Keys::Right) == true) {
            this->rotation_.y = 90;
            this->position_.x += 25.0f + speed_ * 8.0f;
            this->model_.play("Run");
        }
    }

    void Player::putBomb(gdl::Input &input) {
        if (input.isKeyDown(gdl::Keys::B) == true && this->isPush_ == false && this->ammo_ != 0) {
            this->objects_->push_front(new Bomb::Bombe(this->position_.x, this->position_.z, this->objects_));
            this->isPush_ = true;
        } else
            this->isPush_ = false;
    }

    int Player::getAmmo() const {

        return ammo_;
    }

    int Player::getPower() const {

        return power_;
    }

    int Player::getSpeed() const {

        return speed_;
    }

    void Player::ammoUp() {
        if (ammo_ < 6) {

            ammo_ += 1;
        }
    }

    void Player::powerUp() {

        power_ += 1;
    }

    void Player::speedUp() {
        if (speed_ < 4)
            speed_ += 1;
        std::cout << "Vitesse :" << speed_ << std::endl;
    }
}
