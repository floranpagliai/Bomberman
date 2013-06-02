#ifndef __MYCLOCK_HPP__
#define __MYCLOCK_HPP__

#include "AObject.hpp"

class MyClock : public AObject
{
protected:
  gdl::Text		text_;
  gdl::Clock		timer_;
  std::string		s_time;
  float			f_time;

public:
  MyClock();
  ~MyClock();
  
  void	initialize(void);
  void	update(gdl::GameClock const &, gdl::Input &);
  void	draw(void);
  std::string	float2string(float f);
  //  void drawScene(GLDrawable glDrawable, GLUquadric quadric);
};
#endif
