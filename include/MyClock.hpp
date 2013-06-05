#ifndef __MYCLOCK_HPP__
#define __MYCLOCK_HPP__

#include "AObject.hpp"
#include "Camera.hpp"
#include "Player.h"

class Player;
class MyClock : public AObject
{
protected:
  Camera		camera_;  
  Player		*pl_;
  
  gdl::Text		text_;
  gdl::Text		scoreP1_;
  gdl::Text		scoreP2_;
  
  gdl::Clock		timer_;
  
  std::string		s_time;
  std::string		s_text;  

  float			f_time;

  gdl::Color		color_;
  
public:
  MyClock(Player *);
  ~MyClock();
  
  void	initialize(void);
  void	update(gdl::GameClock const &, gdl::Input &);
  void	draw(void);
  std::string	float2string(float f);
};
#endif
