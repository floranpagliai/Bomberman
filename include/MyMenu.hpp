//
// menu.hpp for menu in /home/perez_d//Dropbox/Bomberman/include
//
// Made by damien perez
// Login   <perez_d@epitech.net>
//
// Started on  Fri May 31 15:53:54 2013 damien perez
// Last update Sat Jun  8 18:48:57 2013 lambert cayrel
//

#ifndef	__MY_MENU_HPP__
#define	__MY_MENU_HPP__

#include "AObject.hpp"
#include "MyGame.hpp"
#include "Map.hpp"
#include "MapElement.hpp"

#define WINDOW_HEIGHT 700
#define WINDOW_WIDHT 1024

class MyMenu : public gdl::Game {
public:
    MyMenu();
    virtual ~MyMenu();

    virtual void initialize(void);
    virtual void update(void);
    virtual void draw(void);
    virtual void unload(void);

    void Exit(gdl::Input &);
    void Down(gdl::Input &);
    void Up(gdl::Input &);
    void Return(gdl::Input &);
    void Back(gdl::Input &);
    void LoadLevel2(void);
    void LoadLevel3(void);
    void LoadLevel4(void);
private:
    std::list<AObject*> *objects_;
    sf::Music *intro;
    sf::Music *validation;
    sf::Music *selection;
    bool disp;
    int pos;
    int level;
    Camera camera_;
    float cameraY_;
    float time;
    float time_ret;
    gdl::Clock clock;
    gdl::Clock cl_return;
    gdl::Image image_;

    std::list<std::string> mylist;
    std::list<std::string>::const_iterator it;



};

#endif
