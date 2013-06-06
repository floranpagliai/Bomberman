#include "MyGame.hpp"

void MyGame::initialize(void) {
    window_.setTitle("Bomberman");
    window_.setHeight(700);
    window_.setWidth(1024);
    window_.create();

    camera_.initialize();

    this->countClock_ = 0;

    Map map_("map/map06", &objects_);
    map_.openMap();

    cameraZ_ = camera_.getPosition().z - map_.getMaxX() * 150.0f;
    float cameraY;
    cameraY = map_.getMaxX() * -300.0f;
    camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, cameraZ_);

    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
        (*it)->initialize();
}

void MyGame::update(void) {
    std::list<AObject*>::iterator it;

    for (it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        sleep(0.9);
        (*it)->update(gameClock_, input_);
        if ((*it)->getIsOver() == true) {
            delete (*it);
            it = this->objects_.erase(it);
        }
    }
    //if (camera_.getPosition().z != cameraZ_)
    //camera_.setPosition(camera_.getPosition().x, camera_.getPosition().y, (camera_.getPosition().z - 50.f));
    camera_.update(gameClock_, input_);
        if (this->countClock_ == 0) {
            this->countClock_ = 1;
            this->objects_.push_back(new Display::Timer());
        }

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

std::string MyGame::float2string(float f) {
    std::ostringstream os;
    os << f;
    return os.str();
}

