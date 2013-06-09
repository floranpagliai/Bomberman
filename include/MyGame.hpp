#ifndef __MYGAME_HPP__
#define __MYGAME_HPP__

#include "AObject.hpp"
#include "Camera.hpp"
#include "Map.hpp"
#include "MapElement.hpp"
#include "Display.hpp"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

enum eState {
    MENU = 0,
    GAME
};

class MyGame : public gdl::Game {
private:
    eState state_;
    std::list<AObject*> objects_;
    Camera camera_;
    gdl::Clock timer_;

    sf::Music *introSound;
    sf::Music *validationSound;
    sf::Music *selectionSound;
    sf::Music *bombSound_;
    sf::Music *deathSound_;
    sf::Music *powerupSound_;
    sf::Music *factorySound_;
    sf::Music *iceSound_;
    sf::Music *plaineSound_;

    int nbIA;
    int nbPlayer;
    bool disp;
    int pos;
    int level;

    float time;
    float time_ret;
    gdl::Clock clock;
    gdl::Clock cl_return;
    gdl::Image image_;

    std::list<std::string> mylist;
    std::list<std::string>::const_iterator it;

    float cameraY_;
    int idPlayerW_;

public:
    virtual void initialize();
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void checkWin(void);
    void launchMenu();

    void Exit(void);
    void Down(void);
    void Up(void);
    void Return(void);
    void Back(void);
    void LoadLevel2(void);
    void LoadLevel3(void);
    void LoadLevel4(void);
    void LoadLevel6(void);
    void LoadLevel7(void);
    void LoadLevel9(void);
    void launchGame(void);
    void pause(void);
};

#endif
