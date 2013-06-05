#include "Player.h"

Player::Player(float const x, float const z, std::list<AObject*> *objects) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 0.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->type_ = PLAYER;
    this->ammo_ = 1;
    this->ammoStock_ = ammo_;
    this->power_ = 0;
    this->speed_ = 0;
    this->objects_ = objects;
    this->initialize();
}

Player::~Player() {

}

void Player::initialize(void) {
    this->model_ = gdl::Model::load("assets/marvin.fbx");
    model_.set_default_model_color(gdl::Color(255, 0, 0));
    model_.set_anim_speed("Take 001", 1 + this->speed_); //pour changer la vitesse quand il court
    model_.cut_animation(this->model_, "Take 001", 0, 30, "StartRun");
    model_.cut_animation(this->model_, "Take 001", 35, 53, "Run");
    model_.cut_animation(this->model_, "Take 001", 80, 120, "EndRun");
    model_.cut_animation(this->model_, "Take 001", 0, 0, "Stop");

    powerup = new sf::Music();
    powerup->OpenFromFile("sound/powerup.wav");
}

void Player::update(gdl::GameClock const &gameClock, gdl::Input &input) {
    this->model_.update(gameClock);
    //this->checkMove(input);
    move(input);
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

bool Player::checkMove(gdl::Input &input, float dist, int dir) {
    dist = dist * 3;
    std::list<AObject*>::iterator it;
    for (it = this->objects_->begin(); it != this->objects_->end(); ++it) {
        if (dir == 1) {
            if (this->checkCollision((*it)->getPosition().x + dist, (*it)->getPosition().z) && ((*it)->getType() == WALL || (*it)->getType() == CRATE))
                return false;
        } else {
            if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z + dist) && ((*it)->getType() == WALL || (*it)->getType() == CRATE))
                return false;
        }
        if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && (*it)->getType() == BONUS) {
            if (this->getBonus(dynamic_cast<Bonus *> (*it))) {
                delete (*it);
                objects_->erase(it);
                break;
            }
        } else if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && (*it)->getType() == FLAMME) {
            this->isOver = true;
            break;
        }

    }
    return true;
}

void Player::move(gdl::Input & input) {
    if (input.isKeyDown(gdl::Keys::Up) == true) {
        this->rotation_.y = 180;
        if (checkMove(input, (25.0f + speed_ * 7.0f), 2)) {
            this->position_.z -= 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else
            this->model_.play("Stop");
    } else if (input.isKeyDown(gdl::Keys::Down) == true) {
        this->rotation_.y = 0;
        if (checkMove(input, -(25.0f + speed_ * 7.0f), 2)) {
            this->position_.z += 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else
            this->model_.play("Stop");
    } else if (input.isKeyDown(gdl::Keys::Left) == true) {
        this->rotation_.y = -90;
        if (checkMove(input, (25.0f + speed_ * 7.0f), 1)) {
            this->position_.x -= 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else
            this->model_.play("Stop");
    } else if (input.isKeyDown(gdl::Keys::Right) == true) {
        this->rotation_.y = 90;
        if (checkMove(input, -(25.0f + speed_ * 7.0f), 1)) {
            this->position_.x += 25.0f + speed_ * 7.0f;
            this->model_.play("Run");
        } else
            this->model_.play("Stop");

    } else
        this->model_.play("Stop");

}

void Player::putBomb(gdl::Input & input) {
    std::list<AObject*>::iterator it;
    bool putBomb = true;

    for (it = this->objects_->begin(); it != this->objects_->end(); ++it) {
        if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && (*it)->getType() == BOMB) {
            putBomb = false;
            break;
        }
    }
    if (input.isKeyDown(gdl::Keys::B) == true && this->ammoStock_ != 0 && putBomb == true) {
        this->ammoStock_ -= 1;
        this->objects_->push_front(new Bombe(this->position_.x, this->position_.z, this->power_, this->objects_, this));
    }

}

bool Player::getBonus(Bonus * bonus) {
    if (bonus->getBonusType() == AMMO)
        return this->ammoUp();
    else if (bonus->getBonusType() == POWER)
        return this->powerUp();
    else if (bonus->getBonusType() == SPEED)

        return this->speedUp();
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

bool Player::ammoUp() {
    if (ammo_ <= 5) {
        ammo_ += 1;
        ammoStock_ += 1;
        powerup->Play();
        return true;
    }
    return false;

}

void Player::recupBomb() {

    ammoStock_ += 1;
}

bool Player::powerUp() {
    if (power_ <= 4) {
        power_ += 1;
        powerup->Play();

        return true;
    }
    return false;
}

bool Player::speedUp() {
    if (speed_ < 4) {
        speed_ += 1;
        powerup->Play();
        return true;
    }
    return false;
}


