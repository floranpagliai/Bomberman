#include "MyGame.hpp"

void MyGame::initialize(void) {
    window_.setTitle("Bomberman");
    window_.setHeight(700);
    window_.setWidth(1024);
    window_.create();
    camera_.initialize();

    //Map map_(20, 2, 10, &objects_);
    Map map_("map/usine", USINE, 2, 0, &objects_);

    cameraY_ = map_.getMaxX() * 325.0f;
    this->objects_.push_back(new Display::Timer(&objects_));
    this->bombSound_ = new sf::Music();
    this->deathSound_ = new sf::Music();
    this->powerupSound_ = new sf::Music();
    this->bombSound_->OpenFromFile("assets/sound/explosion.wav");
    this->deathSound_->OpenFromFile("assets/sound/death.wav");
    this->powerupSound_->OpenFromFile("assets/sound/pop.wav");
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->initialize();
}

void MyGame::update(void) {
    camera_.setPosition(camera_.getPosition().x, cameraY_, camera_.getPosition().z);
    camera_.update(gameClock_, input_);
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        sleep(0.9);
        (*it)->update(gameClock_, input_);
        if ((*it)->getIsOver() == true) {
            if ((*it)->getType() == BOMB)
                this->bombSound_->Play();
            if ((*it)->getType() == PLAYER)
                this->deathSound_->Play();
            if ((*it)->getType() == BONUS)
                this->powerupSound_->Play();
            delete (*it);
            it = this->objects_.erase(it);
        }
    }
    this->checkWin();
    if (input_.isKeyDown(gdl::Keys::F1) == true)
        std::cout << camera_.getPosition().y << std::endl;
    if (input_.isKeyDown(gdl::Keys::Escape) == true)
        exit(EXIT_FAILURE);
}

void MyGame::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->draw();
    this->window_.display();
}

void MyGame::unload(void) {
    for (std::list<AObject *>::iterator it = this->objects_.begin(); it != this->objects_.end(); it++)
        delete (*it);
    delete this->bombSound_;
    delete this->deathSound_;
    delete this->powerupSound_;
    this->objects_.clear();
}

void MyGame::checkWin(void) {
    int count = 0;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == PLAYER && (*it)->getId() <= 3)
            count++;
    }
    if (count == 1) {
        for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
            if ((*it)->getType() == PLAYER) {
                std::cout << "GAME OVER: Player " << (*it)->getId() << " win" << std::endl;
                exit(EXIT_SUCCESS);
            }
        }
    }
}