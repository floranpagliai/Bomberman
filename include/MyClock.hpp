#ifndef __MYCLOCK_HPP__
#define __MYCLOCK_HPP__

#include "AObject.hpp"
#include "Camera.hpp"

class MyClock : public AObject
{
protected:
  Camera		camera_;

  gdl::Text		text_;
  gdl::Text		scoreP1_;
  gdl::Text		scoreP2_;

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
#endif
