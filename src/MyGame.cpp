#include "MyGame.hpp"

void MyGame::initialize() {
    window_.setTitle("Bomberman");
    window_.setHeight(WINDOW_HEIGHT);
    window_.setWidth(WINDOW_WIDHT);
    window_.create();
    camera_.initialize();

    level = 1;
    time = 0.00f;
    time_ret = 0.00f;
    mylist.push_back("assets/menu/Prestart.png");
    it = mylist.begin();

    this->introSound = new sf::Music();
    this->validationSound = new sf::Music();
    this->selectionSound = new sf::Music();
    this->bombSound_ = new sf::Music();
    this->deathSound_ = new sf::Music();
    this->powerupSound_ = new sf::Music();

    this->plaineSound_ = new sf::Music();
    this->factorySound_ = new sf::Music();
    this->iceSound_ = new sf::Music();

    this->plaineSound_->OpenFromFile("assets/sound/peaceful_land.wav");
    this->factorySound_->OpenFromFile("assets/sound/madness_factory.wav");
    this->iceSound_->OpenFromFile("assets/sound/ice_kingdom.wav");

    this->bombSound_->OpenFromFile("assets/sound/explosion.wav");
    this->deathSound_->OpenFromFile("assets/sound/death.wav");
    this->powerupSound_->OpenFromFile("assets/sound/pop.wav");
    this->introSound->OpenFromFile("assets/sound/musicintro.wav");
    this->selectionSound->OpenFromFile("assets/sound/selection.wav");
    this->validationSound->OpenFromFile("assets/sound/validation.wav");
    this->selectionSound->SetVolume(50.00f);
    this->introSound->SetLoop(true);

    this->plaineSound_->SetLoop(true);
    this->factorySound_->SetLoop(true);
    this->iceSound_->SetLoop(true);

    this->launchMenu();
}

void MyGame::update(void) {
  if (this->state_ == MENU) {
    camera_.setPosition(camera_.getPosition().x, 0, camera_.getPosition().z);
    cl_return.update();
    clock.update();
    time_ret = time_ret + cl_return.getElapsedTime();
    time = time + clock.getElapsedTime();

    if (time > 0.05f) {
      Exit();
      if (level != 1)
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
    if ((level == 5 && (pos == 1 || pos == 2 || pos == 3)) || (level == 8 && (pos == 1 || pos == 2 || pos == 3 || pos == 4))) {
      launchGame();
    }
  } else {
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
    if (input_.isKeyDown(gdl::Keys::Escape) == true) {
      this->objects_.push_back(new Display::Pause());
      if(input_.isKeyDown(gdl::Keys::Back) == true) {
	launchGame();
      }
    }
  }
}
  void MyGame::draw(void) {
    if (this->state_ == MENU) {
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
    } else {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
      glClearDepth(1.f);
      for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
	(*it)->draw();
      this->window_.display();
    }
  }


  void MyGame::unload(void) {
    for (std::list<AObject *>::iterator it = this->objects_.begin(); it != this->objects_.end(); it++)
      delete (*it);
    this->objects_.clear();
  }

void MyGame::checkWin(void) {
    int countP = 0;
    int countIA = 0;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it) {
        if ((*it)->getType() == PLAYER && (*it)->getId() < 3) {
            this->idPlayerW_ = (*it)->getId();
            countP++;
        }
        if ((*it)->getType() == PLAYER && (*it)->getId() == 3)
            countIA++;
    }
    if (countP == 1 && countIA == 0) {
        this->objects_.push_back(new Display::ResultFinal(this->idPlayerW_));
        this->draw();
        sleep(3);
        this->launchMenu();
    } else if (countP == 0 && countIA > 0) {
        this->objects_.push_back(new Display::ResultFinal(3));
        this->draw();
        sleep(3);
        this->launchMenu();
    } else if (countP == 0 && countIA == 0) {
        this->objects_.push_back(new Display::ResultFinal(3));
        this->draw();
        sleep(3);
        this->launchMenu();
    }
}

void MyGame::launchMenu() {
  this->iceSound_->Stop();
  this->plaineSound_->Stop();
  this->factorySound_->Stop();
  this->introSound->Play();
  for (std::list<AObject *>::iterator it = this->objects_.begin(); it != this->objects_.end(); it++)
    delete (*it);
  this->objects_.clear();
  this->state_ = MENU;
  this->level = 1;
  this->disp = true;
  clock.play();
  cl_return.play();

}

void MyGame::Exit(void) {
    if (input_.isKeyDown(gdl::Keys::Escape) == true)
        exit(EXIT_FAILURE);
}

void MyGame::Down(void) {
    if (input_.isKeyDown(gdl::Keys::Down) == true) {
        disp = true;
        if (pos < mylist.size()) {
            selectionSound->Play();
            it++;
            pos++;
        }
    }
}

void MyGame::Up(void) {
    if (input_.isKeyDown(gdl::Keys::Up) == true) {
        disp = true;
        if (it != mylist.begin()) {
            selectionSound->Play();
            it--;
            pos--;
        }
    }
}

void MyGame::Return(void) {
  if (input_.isKeyDown(gdl::Keys::Return) == true && time_ret > 0.50f) {
    if ((pos == 5 && level == 2) || (pos == 11 && level == 3) || (pos == 5 && level == 4) || (pos == 5 && level == 7) || (level == 7 && pos == 5) || (level == 6 && pos == 2) || (level == 9 && pos == 1))
      exit(EXIT_FAILURE);
    if (level == 3)
      this->nbIA = pos - 1;
    if (this->nbIA == 0 && this->nbPlayer == 1)
      this->nbIA++;
    level++;
    if (level == 3 && pos == 3)
      level = 6;
    if (level == 5 && pos == 4)
      level = 7;
    if (level == 3 && pos == 4)
      level = 9;
    LoadLevel2();
    disp = true;
    validationSound->Play();
    time_ret = 0.00f;
  }
}

void MyGame::Back(void) {
    if (input_.isKeyDown(gdl::Keys::Back)) {
        disp = true;
        level = 2;
        pos = 1;
        LoadLevel2();
    }
}

void MyGame::LoadLevel2(void) {
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

void MyGame::LoadLevel3(void) {
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

void MyGame::LoadLevel4(void) {
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
    LoadLevel6();
}

void MyGame::LoadLevel6(void) {
    if (level == 6) {
        std::cout << "TOTO" << std::endl;
        pos = 1;
        mylist.clear();
        mylist.push_back("assets/menu/5.load/load_game.png");
        mylist.push_back("assets/menu/5.load/quit.png");
        it = mylist.begin();
    }
    LoadLevel7();
}

void MyGame::LoadLevel7(void) {
    if (level == 7) {
        pos = 1;
        mylist.clear();
        mylist.push_back("assets/menu/7.size/7.20x20.png");
        mylist.push_back("assets/menu/7.size/7.30x30.png");
        mylist.push_back("assets/menu/7.size/7.40x40.png");
        mylist.push_back("assets/menu/7.size/7.50x50.png");
        mylist.push_back("assets/menu/7.size/7.quit.png");
        it = mylist.begin();
    }
    LoadLevel9();
}

void MyGame::LoadLevel9(void) {
    if (level == 9) {
        pos = 1;
        mylist.clear();
        mylist.push_back("assets/menu/6.score/6.score.png");
        it = mylist.begin();
    }
}

void MyGame::launchGame() {
    introSound->Stop();
    if (level == 5 && pos == 1) {
        Map map((char*) "map/plaine", PLAINE, nbPlayer, nbIA, &this->objects_);
        cameraY_ = map.getMaxX() * 325.0f;
	this->plaineSound_->Play();
    } else if (level == 5 && pos == 2) {
        Map map((char*) "map/usine", USINE, nbPlayer, nbIA, &this->objects_);
        cameraY_ = map.getMaxX() * 325.0f;
	this->factorySound_->Play();
    } else if (level == 5 && pos == 3) {
        Map map((char*) "map/plaine", POLENORD, nbPlayer, nbIA, &this->objects_);
        cameraY_ = map.getMaxX() * 325.0f;
	this->iceSound_->Play();
    } else {
        Map map((pos * 10) + 10, nbPlayer, nbIA, &this->objects_);
        cameraY_ = map.getMaxX() * 325.0f;
    }
    this->objects_.push_back(new Display::Timer(&objects_));
    camera_.setPosition(camera_.getPosition().x, cameraY_, camera_.getPosition().z);
    this->state_ = GAME;
    for (std::list<AObject*>::iterator it = this->objects_.begin(); it != this->objects_.end(); ++it)
      (*it)->initialize();
}
