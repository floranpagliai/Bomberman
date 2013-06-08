#include "MyMenu.hpp"

MyMenu::MyMenu() {
}

MyMenu::~MyMenu() {

}

void MyMenu::initialize() {
    clock.play();
    cl_return.play();
    window_.setTitle("Menu Bomberman");
    window_.setHeight(WINDOW_HEIGHT);
    window_.setWidth(WINDOW_WIDHT);
    window_.create();
    camera_.initialize();

    intro = new sf::Music();
    validation = new sf::Music();
    selection = new sf::Music();

    intro->OpenFromFile("sound/musicintro.wav");
    intro->SetLoop(true);
    selection->OpenFromFile("sound/selection.wav");
    selection->SetVolume(50.00f);
    validation->OpenFromFile("sound/validation.wav");
    intro->Play();

    level = 1;
    time = 0.00f;
    time_ret = 0.00f;
    pos = 1;
    mylist.push_back("assets/menu/Prestart.png");
    it = mylist.begin();
}

void MyMenu::update() {
    camera_.setPosition(camera_.getPosition().x, 0, camera_.getPosition().z);
    cl_return.update();
    clock.update();
    time_ret = time_ret + cl_return.getElapsedTime();
    time = time + clock.getElapsedTime();

    if (time > 0.05f) {
        Exit(input_);
        Down(input_);
        Up(input_);
        Return(input_);
        Back(input_);
        time = 0.00f;
    }
    if (disp == true) {
        std::cout << "It = [" << *it << "] Pos = [" << pos << "] Level = [" << level << "]" << std::endl;
        this->image_ = gdl::Image::load(*it);
        disp = false;

    }
    if (level == 5) {
        if (level == 5 && pos == 1) {
            MyGame game((char*) "map/plaine", PLAINE, 1, pos);
            game.run();
        } else if (level == 5 && pos == 2) {
            MyGame game((char*) "map/usine", USINE, 1, pos);
            game.run();
        }
        else if (level == 5 && pos == 3) {
            MyGame game((char*) "map/usine", POLENORD, 1, pos);
            game.run();
        }
        this->initialize();
    }

    //this->initialize();
}

void MyMenu::unload(void) {

}

void MyMenu::draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.f);

    image_.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();

    glViewport(0, 0, WINDOW_WIDHT, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WINDOW_WIDHT, 0, WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

    //glColor3f(255, 255, 255);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, WINDOW_HEIGHT, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(WINDOW_WIDHT, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(WINDOW_WIDHT, WINDOW_HEIGHT, 0.0f);

    glEnd();
    glPopMatrix();
}

void MyMenu::Exit(gdl::Input &input_) {
    if (input_.isKeyDown(gdl::Keys::Escape) == true)
        exit(EXIT_FAILURE);
}

void MyMenu::Down(gdl::Input &input_) {
    if (input_.isKeyDown(gdl::Keys::Down) == true) {
        disp = true;
        if (pos < mylist.size()) {
            selection->Play();
            it++;
            pos++;
        }
    }
}

void MyMenu::Up(gdl::Input &input_) {
    if (input_.isKeyDown(gdl::Keys::Up) == true) {
        disp = true;
        if (it != mylist.begin()) {
            selection->Play();
            it--;
            pos--;
        }
    }
}

void MyMenu::Return(gdl::Input &input_) {
    if (input_.isKeyDown(gdl::Keys::Return) == true && time_ret > 0.50f) {
        if ((pos == 5 && level == 2) || (pos == 11 && level == 3) || (pos == 5 && level == 4))
            exit(EXIT_FAILURE);
        level++;
        LoadLevel2();
        disp = true;
        validation->Play();
        time_ret = 0.00f;
    }
}

void MyMenu::Back(gdl::Input &input_) {
    if (input_.isKeyDown(gdl::Keys::Back)) {
        disp = true;
        std::cout << "Back" << std::endl;
        level = 2;
        pos = 1;
        LoadLevel2();
    }
}

void MyMenu::LoadLevel2(void) {
    std::cout << "LEVEL 2 lvl=" << level << std::endl;
    if (level == 2) {
        pos = 1;
        std::cout << "POS = " << pos << std::endl;
        mylist.clear();
        mylist.push_back("assets/menu/1.Play/1.1_player.png");
        mylist.push_back("assets/menu/1.Play/1.2_players.png");
        mylist.push_back("assets/menu/1.Play/1.load_game.png");
        mylist.push_back("assets/menu/1.Play/1.score.png");
        mylist.push_back("assets/menu/1.Play/1.quit.png");
        it = mylist.begin();
    }
    LoadLevel3();
}

void MyMenu::LoadLevel3(void) {
    std::cout << "LEVEL 3 lvl=" << level << std::endl;
    if (level == 3 && pos == 1) {
        std::cout << "In lvl 3" << std::endl;
        mylist.clear();
        mylist.push_back("assets/menu/3.nbr_ia/ia.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia1.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia2.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia3.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia4.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia5.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia6.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia7.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia8.png");
        mylist.push_back("assets/menu/3.nbr_ia/ia9.png");
        mylist.push_back("assets/menu/3.nbr_ia/quit.png");
        it = mylist.begin();
    }
    LoadLevel4();
}

void MyMenu::LoadLevel4(void) {
    if (level == 4) {
        pos = 1;
        mylist.clear();
        mylist.push_back("assets/menu/4.map/4.peaceful_land.png");
        mylist.push_back("assets/menu/4.map/4.madness_factory.png");
        mylist.push_back("assets/menu/4.map/4.ice_kingdom.png");
        mylist.push_back("assets/menu/4.map/4.random.png");
        mylist.push_back("assets/menu/4.map/4.quit.png");
        it = mylist.begin();
    }
}