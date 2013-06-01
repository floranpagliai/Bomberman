#include "MyGame.hpp"

void MyGame::initialize(void) {
    window_.setTitle("Bomberman");
    window_.setHeight(700);
    window_.setWidth(1024);
    window_.create();
    camera_.initialize();
    Map map_("map/map09", &objects_);
    map_.openMap();
    cameraZ_ = camera_.getPosition().z - map_.getMaxX() * 550.0f;
    camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, cameraZ_);
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->initialize();
}

void MyGame::update(void) {
    std::list<AObject*>::iterator it;
    for (it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        (*it)->update(gameClock_, input_);
        if ((*it)->getIsOver() == true) {
            delete (*it);
            it = this->objects_.erase(it);
        }
    }
    if (camera_.getPosition().z != 0)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, (camera_.getPosition().z - 50.f));
    camera_.update(gameClock_, input_);
    if (input_.isKeyDown(gdl::Keys::F1) == true && camera_.getPosition().z >= 0)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, (camera_.getPosition().z + 50.f));
    if (input_.isKeyDown(gdl::Keys::F2) == true && camera_.getPosition().z > 0)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, (camera_.getPosition().z - 50.f));
    if (input_.isKeyDown(gdl::Keys::F3) == true)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, cameraZ_);
    if (input_.isKeyDown(gdl::Keys::F4) == true)
        camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, 0.0f);
    if (input_.isKeyDown(gdl::Keys::Escape) == true)
        exit(EXIT_FAILURE);
}

void MyGame::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);

    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
        (*itb)->draw();
    this->window_.display();
}

void MyGame::unload(void) {
    std::list<AObject *>::iterator it = this->objects_.begin();
    for (; it != this->objects_.end(); it++)
        delete *it;
    this->objects_.clear();
}