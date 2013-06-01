#include "Player.hpp"

namespace Model {

    Player::Player(float const x, float const z, std::list<AObject*> *objects) {
        this->position_.x = x * (BLOCK_SIZE * 2);
        this->position_.y = 0.0f;
        this->position_.z = z * (BLOCK_SIZE * 2);
        this->type_ = PLAYER;
        this->ammo_ = 1;
        this->power_ = 0;
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

    void Player::update(gdl::GameClock const &gameClock, gdl::Input &input) {
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

        for (int i = 0; i < 4; i++) {
            std::list<AObject*>::iterator it;
            for (it = this->objects_->begin(); it != this->objects_->end(); ++it) {
                if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && (*it)->getType() == BONUS) {
                    delete (*it);
                    objects_->erase(it);
                    this->powerUp();
                    break;
                }
            }
        }
        move(input);
        if (input.isKeyDown(gdl::Keys::S) == true) {
            this->speedUp();
        }
        if (input.isKeyDown(gdl::Keys::A) == true) {
            this->ammoUp();
        }
    }

    void Player::move(gdl::Input & input) {
        if (input.isKeyDown(gdl::Keys::Up) == true) {
            this->rotation_.y = 180;
            this->position_.z -= 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else if (input.isKeyDown(gdl::Keys::Down) == true) {
            this->rotation_.y = 0;
            this->position_.z += 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else if (input.isKeyDown(gdl::Keys::Left) == true) {
            this->rotation_.y = -90;
            this->position_.x -= 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else if (input.isKeyDown(gdl::Keys::Right) == true) {
            this->rotation_.y = 90;
            this->position_.x += 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else
            this->model_.play("Stop");
    }

    void Player::putBomb(gdl::Input & input) {
        if (input.isKeyDown(gdl::Keys::B) == true && this->isPush_ == false && this->ammo_ != 0) {
            this->objects_->push_front(new Bomb::Bombe(this->position_.x, this->position_.z, this->power_, this->objects_));
            ammo_--;
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
        if (ammo_ <= 1)
            ammo_ += 1;
    }

    void Player::powerUp() {
        if (power_ <= 4)
            power_ += 1;
    }

    void Player::speedUp() {
        if (speed_ < 4)
            speed_ += 1;
    }
}
