#include "MyGame.hpp"

//création window, add objects, initialize objects

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
    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
        (*itb)->initialize();
}

//update objects

void MyGame::update(void) {
    std::list<AObject*>::iterator itb;
    for (itb = this->objects_.begin(); itb != this->objects_.end(); ++itb) {
        (*itb)->update(gameClock_, input_);
        if ((*itb)->getIsOver() == true ) {
            itb = this->objects_.erase(itb);
        }
    }
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

//dump buffers, call method object draw and display rendenring in the window

void MyGame::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);
    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
        (*itb)->draw();
    this->window_.display();
}

//free all

void MyGame::unload(void) {
    /*
      doit liberer la mémoire lorsque la fenêtre est fermée !!
     */
}