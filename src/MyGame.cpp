#include "MyGame.hpp"


//création window, add objects, initialize objects

void MyGame::initialize(void) {
    window_.setTitle("Bomberman");
    window_.setHeight(700);
    window_.setWidth(1024);
    window_.create();
    camera_.initialize();

    objects_.push_back(new Model::Player(0.0f, 0.0f, &objects_));
    int i = -10;
    int x = -10;
    while (i <= 10) {
        while (x <= 10) {
            if ( x == -10 || x == 10 || i == -10 || i == 10)
                objects_.push_back(new MapElement::Wall(x, i, &objects_, camera_));
            objects_.push_back(new MapElement::Ground(x, i, &objects_, camera_));
            x++;
        }
        x = -10;
        i++;
    }
    objects_.push_back(new MapElement::Crate(1.0f, 0.0f, &objects_, camera_));
    objects_.push_back(new MapElement::Crate(9.0f, 0.0f, &objects_, camera_));
    objects_.push_back(new MapElement::Crate(5.0f, 3.0f, &objects_, camera_));
    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
        (*itb)->initialize();
}

//update objects

void MyGame::update(void) {
    std::list<AObject*>::iterator itb = this->objects_.begin();
    for (; itb != this->objects_.end(); ++itb)
        (*itb)->update(gameClock_, input_);
    camera_.update(gameClock_, input_);
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
