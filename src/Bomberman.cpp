#include "Bomberman.h"

t_move moveP1[5] = {
    {
        gdl::Keys::Up, 180, 0, -1
    },
    {
        gdl::Keys::Down, 0, 0, 1
    },
    {
        gdl::Keys::Left, -90, -1, 0
    },
    {
        gdl::Keys::Right, 90, 1, 0
    },
    {
        gdl::Keys::B, 0, 0, 0
    }
};

t_move moveP2[5] = {
    {
        gdl::Keys::Z, 180, 0, -1
    },
    {
        gdl::Keys::S, 0, 0, 1
    },
    {
        gdl::Keys::Q, -90, -1, 0
    },
    {
        gdl::Keys::D, 90, 1, 0
    },
    {
        gdl::Keys::Tab, 0, 0, 0
    }
};

Bomberman::Bomberman(float const x, float const z, int const id, std::list<AObject*> *objects) {
    this->position_.x = x * (BLOCK_SIZE * 2);
    this->position_.y = 0.0f;
    this->position_.z = z * (BLOCK_SIZE * 2);
    this->type_ = PLAYER;
    this->id_ = id;
    this->ammo_ = 1;
    this->ammoStock_ = ammo_;
    this->power_ = 0;
    this->speed_ = 0;
    this->objects_ = objects;
    this->initialize();
}

Bomberman::~Bomberman() {
    deathSound_->Play();
}

void Bomberman::initialize(void) {
    this->model_ = gdl::Model::load("assets/marvin.fbx");
    model_.cut_animation(this->model_, "Take 001", 0, 30, "StartRun");
    model_.cut_animation(this->model_, "Take 001", 35, 53, "Run");
    model_.cut_animation(this->model_, "Take 001", 80, 120, "EndRun");
    model_.cut_animation(this->model_, "Take 001", 0, 0, "Stop");
    if (this->id_ == 0)
        model_.set_default_model_color(gdl::Color(255, 0, 0));
    else
        model_.set_default_model_color(gdl::Color(0, 0, 255));

    powerupSound_ = new sf::Music();
    powerupSound_->OpenFromFile("assets/sound/pop.wav");
    deathSound_ = new sf::Music();
    deathSound_->OpenFromFile("assets/sound/death.wav");
}

void Bomberman::update(gdl::GameClock const &gameClock, gdl::Input &input) {
    model_.set_anim_speed("Take 001", 1 * this->speed_);
    this->model_.update(gameClock);
    this->move(input);
}

void Bomberman::draw(void) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glTranslatef(this->position_.x, this->position_.y, this->position_.z);
    glRotatef(this->rotation_.y, 0.0f, 1.0f, 0.0f);

    this->model_.draw();
    glPopMatrix();
}

bool Bomberman::checkMove(gdl::Input &input, float distX, float distZ) {
    distX = distX * 3;
    distZ = distZ * 3;
    std::list<AObject*>::iterator it;
    for (it = this->objects_->begin(); it != this->objects_->end(); ++it) {
        if (this->checkCollision((*it)->getPosition().x - distX, (*it)->getPosition().z) && ((*it)->getType() == WALL || (*it)->getType() == CRATE || (*it)->getType() == BOMB)) {
            if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && ((*it)->getType() == BOMB))
                return true;
            return false;
        } else if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z - distZ) && ((*it)->getType() == WALL || (*it)->getType() == CRATE || (*it)->getType() == BOMB)) {
            if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && ((*it)->getType() == BOMB))
                return true;
            return false;
        } else if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && (*it)->getType() == BONUS && this->getBonus(dynamic_cast<Bonus *> (*it))) {
            delete (*it);
            objects_->erase(it);
            powerupSound_->Play();

            break;
        }
    }
    return true;
}

void Bomberman::move(gdl::Input & input) {
    //    if (input.isKeyDown(gdl::Keys::Up) == true) {
    //        this->rotation_.y = 180;
    //        if (checkMove(input, (25.0f + speed_ * 7.0f), 2)) {
    //            this->position_.z -= 25.0f + speed_ * 7.0f;
    //            this->model_.play("Run");
    //        } else
    //            this->model_.play("Stop");
    //    } else if (input.isKeyDown(gdl::Keys::Down) == true) {
    //        this->rotation_.y = 0;
    //        if (checkMove(input, -(25.0f + speed_ * 7.0f), 2)) {
    //            this->position_.z += 25.0f + speed_ * 7.0f;
    //            this->model_.play("Run");
    //        } else
    //            this->model_.play("Stop");
    //    } else if (input.isKeyDown(gdl::Keys::Left) == true) {
    //        this->rotation_.y = -90;
    //        if (checkMove(input, (25.0f + speed_ * 7.0f), 1)) {
    //            this->position_.x -= 25.0f + speed_ * 7.0f;
    //            this->model_.play("Run");
    //        } else
    //            this->model_.play("Stop");
    //    } else if (input.isKeyDown(gdl::Keys::Right) == true) {
    //        this->rotation_.y = 90;
    //        if (checkMove(input, -(25.0f + speed_ * 7.0f), 1)) {
    //            this->position_.x += 25.0f + speed_ * 7.0f;
    //            this->model_.play("Run");
    //        } else
    //            this->model_.play("Stop");
    //
    //    } else
    //        this->model_.play("Stop");
    //    if (input.isKeyDown(gdl::Keys::B) == true)
    //        this->putBomb(input);
    for (int i = 0; i < 4; i++) {
        if (input.isKeyDown(getKeys()[i].key) == true) {
            this->rotation_.y = getKeys()[i].angle;
            if (checkMove(input, (25.0f + speed_ * 7.0f) * getKeys()[i].coefX, (25.0f + speed_ * 7.0f) * getKeys()[i].coefZ)) {
                this->position_.x += (25.0f + speed_ * 7.0f) * getKeys()[i].coefX;
                this->position_.z += (25.0f + speed_ * 7.0f) * getKeys()[i].coefZ;
                this->model_.play("Run");
            } else
                this->model_.play("Stop");
        }
    }

    if (input.isKeyDown(getKeys()[4].key) == true)
        this->putBomb(input);
}

void Bomberman::putBomb(gdl::Input & input) {
    std::list<AObject*>::iterator it;
    bool putBomb = true;

    for (it = this->objects_->begin(); it != this->objects_->end(); ++it) {
        if (this->checkCollision((*it)->getPosition().x, (*it)->getPosition().z) && (*it)->getType() == BOMB) {
            putBomb = false;
            break;
        }
    }
    if (this->ammoStock_ != 0 && putBomb == true) {

        this->ammoStock_ -= 1;
        this->objects_->push_front(new Bombe(this->position_.x, this->position_.z, this->power_, this->objects_, this));
    }

}

bool Bomberman::getBonus(Bonus * bonus) {
    if (bonus->getBonusType() == AMMO)
        return this->ammoUp();
    else if (bonus->getBonusType() == POWER)
        return this->powerUp();
    else if (bonus->getBonusType() == SPEED)

        return this->speedUp();
}

t_move* Bomberman::getKeys() const {
    if (this->id_ == 0)
        return (moveP1);

    else
        return (moveP2);
}

int Bomberman::getAmmo() const {

    return ammo_;
}

int Bomberman::getPower() const {

    return power_;
}

int Bomberman::getSpeed() const {

    return speed_;
}

bool Bomberman::ammoUp() {
    if (ammo_ <= 5) {
        ammo_ += 1;
        ammoStock_ += 1;

        return true;
    }
    return false;

}

void Bomberman::recupBomb() {

    ammoStock_ += 1;
}

bool Bomberman::powerUp() {
    if (power_ <= 4) {
        power_ += 1;

        return true;
    }
    return false;
}

bool Bomberman::speedUp() {
    if (speed_ < 4) {
        speed_ += 1;
        return true;
    }
    return false;
}



