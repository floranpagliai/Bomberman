#include "MyMenu.hpp"

void MyMenu::initialize() {
    clock.play();
    cl_return.play();
    window_.setTitle("Menu Bomberman");
    window_.setHeight(WINDOW_HEIGHT);
    window_.setWidth(WINDOW_WIDHT);
    window_.create();
    camera_.initialize();

    introSound = new sf::Music();
    validationSound = new sf::Music();
    selectionSound = new sf::Music();

    introSound->OpenFromFile("assets/sound/musicintro.wav");
    introSound->SetLoop(true);
    selectionSound->OpenFromFile("assets/sound/selection.wav");
    selectionSound->SetVolume(50.00f);
    validationSound->OpenFromFile("assets/sound/validation.wav");
    introSound->Play();

    level = 1;
    time = 0.00f;
    time_ret = 0.00f;
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
        Exit();
        Down();
        Up();
        Return();
        Back();
        time = 0.00f;
    }
    if (disp == true) {
        this->image_ = gdl::Image::load(*it);
        disp = false;
    }
    if (level == 5) {
        launchGame();
    }
}

void MyMenu::unload(void) {
    this->mylist.clear();

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

void MyMenu::Exit(void) {
    if (input_.isKeyDown(gdl::Keys::Escape) == true)
        exit(EXIT_FAILURE);
}

void MyMenu::Down(void) {
    if (input_.isKeyDown(gdl::Keys::Down) == true) {
        disp = true;
        if (pos < mylist.size()) {
            selectionSound->Play();
            it++;
            pos++;
        }
    }
}

void MyMenu::Up(void) {
    if (input_.isKeyDown(gdl::Keys::Up) == true) {
        disp = true;
        if (it != mylist.begin()) {
            selectionSound->Play();
            it--;
            pos--;
        }
    }
}

void MyMenu::Return(void) {
    if (input_.isKeyDown(gdl::Keys::Return) == true && time_ret > 0.50f) {
        if ((pos == 5 && level == 2) || (pos == 11 && level == 3) || (pos == 5 && level == 4))
            exit(EXIT_FAILURE);
        if (level == 3)
            this->nbIA = pos - 1;
        if (this->nbIA == 0 && this->nbPlayer == 1)
            this->nbIA++;
        level++;
        LoadLevel2();
        disp = true;
        validationSound->Play();
        time_ret = 0.00f;
    }
}

void MyMenu::Back(void) {
    if (input_.isKeyDown(gdl::Keys::Back)) {
        disp = true;
        level = 2;
        pos = 1;
        LoadLevel2();
    }
}

void MyMenu::LoadLevel2(void) {
    if (level == 2) {
        pos = 1;
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
    if (level == 3 && (pos == 1 || pos == 2)) {
        this->nbPlayer = pos;
        pos = 1;
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

void MyMenu::launchGame() {
    introSound->Stop();
    if (level == 5 && pos == 1) {
        MyGame game((char*) "map/plaine", PLAINE, nbPlayer, nbIA);
        game.run();
        game.unload();
    } else if (level == 5 && pos == 2) {
        MyGame game((char*) "map/usine", USINE, nbPlayer, nbIA);
        game.run();
    } else if (level == 5 && pos == 3) {
        MyGame game((char*) "map/usine", POLENORD, nbPlayer, nbIA);
        game.run();

    } else {
        MyGame game(nbPlayer, nbIA);
        game.run();
    }

}
