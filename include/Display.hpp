#ifndef __DISPLAY_HPP__
#define __DISPLAY_HPP__

#include "AObject.hpp"
#include "Camera.hpp"
#include "Bomberman.h"

class Bomberman;

#define   DISPLAY_SIZE 500

namespace Display{

  class Timer : public AObject {
  private:
    Camera	camera_;
    gdl::Text	T_time_;
    gdl::Clock	C_timer_;
    gdl::Image	texture_;

    float	f_time_;
    std::string	s_time_;

    std::list<AObject*>	*objects_;
  public:
    Timer(std::list<AObject*> *);
    ~Timer();

    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);

    std::string	float2string(float f);
  };
  //  class Bomberman;
  class DisplayPlayer : public AObject {
  private:
    Camera	camera__;
    gdl::Text	score_;
    gdl::Text	nb_Bomb_;
    gdl::Text	speed_;
    gdl::Text	power_;
    gdl::Text	Ammo_;


    std::string	s_bomb;
    int		i_bomb;

    std::string s_speed_;
    int		i_speed_;

    std::string	s_power_;
    int		i_power_;

    Bomberman	*p_player;

    public:
    DisplayPlayer(Bomberman *);
    ~DisplayPlayer();

    void	initialize(void);
    void	update(gdl::GameClock const &, gdl::Input &);
    void	draw(void);

    std::string	intToStr(int);
  };

}
#endif


/*
class MyClock : public AObject
{
protected:
  Camera		camera_;

  gdl::Text		text_;
  gdl::Text		scoreP1_;
  gdl::Text		scoreP2_;
  gdl::Text		nb_BombP1_;
  gdl::Text		nb_BombP2_;

  gdl::Clock		timer_;

  std::string		s_time;
  std::string		s_text;

  float			f_time;

  gdl::Color		color_;

public:
  MyClock();
  ~MyClock();

  void	initialize(void);
  void	update(gdl::GameClock const &, gdl::Input &);
  void	draw(void);
  std::string	float2string(float f);
};
*/
