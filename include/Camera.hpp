#ifndef __CAMERA_HPP_
#define __CAMERA_HPP_

#include <GL/gl.h>
#include <GL/glu.h>

#include <GameClock.hpp>
#include <Input.hpp>
#include "Vector3f.hpp"
#include "Window.hpp"

class Camera {
private:
  Vector3f	position_;
  Vector3f	rotation_;

public:
  Camera(void);

  void	initialize(void);
  void	update(gdl::GameClock const &, gdl::Input &);

  Vector3f getPosition(void) const;
  Vector3f getRotation(void) const;

  void setPosition(float const x, float const y, float const z);
};

#endif
