//
// menu.hpp for menu in /home/perez_d//Dropbox/Bomberman/include
//
// Made by damien perez
// Login   <perez_d@epitech.net>
//
// Started on  Fri May 31 15:53:54 2013 damien perez
// Last update Sat Jun  8 23:30:33 2013 lambert cayrel
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
  virtual void initialize(void);
  virtual void update(void);
  virtual void draw(void);
  virtual void unload(void);

  void Exit(void);
  void Down(void);
  void Up(void);
  void Return(void);
  void Back(void);
  void LoadLevel2(void);
  void LoadLevel3(void);
  void LoadLevel4(void);
  void launchGame(void);

private:
  std::list<AObject*> *objects_;
  Camera camera_;

  sf::Music *introSound;
  sf::Music *validationSound;
  sf::Music *selectionSound;

  int	nbIA;
  int	nbPlayer;
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



};

#endif
