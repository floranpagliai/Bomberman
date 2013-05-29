#include "MyGame.hpp"


//création window, add objects, initialize objects

void MyGame::initialize(void) {
    window_.setTitle("Bomberman");
    window_.setHeight(700);
    window_.setWidth(1024);
    window_.create();
    camera_.initialize();

    openMap("map/map2");
    objects_.push_back(new Model::Player(0.0f, 0.0f, &objects_));
    //    int i = -10;
    //    int x = -10;
    //    while (i <= 10) {
    //        while (x <= 10) {
    //            if (x == -10 || x == 10 || i == -10 || i == 10)
    //                objects_.push_back(new MapElement::Wall(x, i, &objects_, camera_));
    //            objects_.push_back(new MapElement::Ground(x, i, &objects_, camera_));
    //            x++;
    //        }
    //        x = -10;
    //        i++;
    //    }
    //    objects_.push_back(new MapElement::Crate(1.0f, 0.0f, &objects_, camera_));
    //    objects_.push_back(new MapElement::Crate(9.0f, 0.0f, &objects_, camera_));
    //    objects_.push_back(new MapElement::Crate(5.0f, 3.0f, &objects_, camera_));
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

void MyGame::openMap(const char *name) {
    std::ifstream file(name, std::ios::in);
    std::string str;
    int x = 0;
    int z = 0;

    if (file) {
        while (getline(file, str)) {
            std::string::iterator it = str.begin();
            while (it != str.end()) {
                if (*it == '1' || *it == '7') {
                    objects_.push_back(new MapElement::Ground(x, z, &objects_, camera_));
                } else if (*it == '2') {
                    objects_.push_back(new MapElement::Wall(x, z, &objects_, camera_));
                } else if (*it == '3') {
                    objects_.push_back(new MapElement::Crate(x, z, &objects_, camera_));
                }
                it++;
                x++;
            }
            x = 0;
            z++;
        }
        file.close();
    } else
        std::cout << "Bad Map File" << std::endl;
}