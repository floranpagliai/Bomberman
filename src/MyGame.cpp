#include "MyGame.hpp"

void MyGame::initialize(void) {
    MyMenu menu;
    menu.run();
    window_.setTitle("Bomberman");
    window_.setHeight(700);
    window_.setWidth(1024);
    window_.create();
    camera_.initialize();

    //Map map_(60, 2, 11, &objects_);
    Map map_("map/usine", POLENORD, 2, 0, &objects_);

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
    if (input_.isKeyDown(gdl::Keys::F1) == true && camera_.getPosition().z != 5000.0f)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, camera_.getPosition().z + 50.0f);
    if (input_.isKeyDown(gdl::Keys::F2) == true && camera_.getPosition().z != 900.0f)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, camera_.getPosition().z - 50.0f);
    if (input_.isKeyDown(gdl::Keys::F3) == true)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, 900.0f);
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
    int countP = 0;
    int countIA = 0;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == PLAYER && (*it)->getId() < 3)
            countP++;
        if ((*it)->getType() == PLAYER && (*it)->getId() == 3)
            countIA++;
    }
    if (countP == 1 && countIA == 0) {
        for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
            if ((*it)->getType() == PLAYER) {
                std::cout << "GAME OVER: Player " << (*it)->getId() << " win" << std::endl;
                exit(EXIT_SUCCESS);
            }
        }
    }
    if (countP == 0 && countIA > 0) {
        std::cout << "GAME OVER: Computer win" << std::endl;
        exit(EXIT_SUCCESS);
    }
}