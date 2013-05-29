#ifndef __AOBJECT__HPP__
#define __AOBJECT__HPP__

#include "GameClock.hpp"
#include "Input.hpp"
#include "Image.hpp"
#include "Vector3f.hpp"

#define   BLOCK_SIZE 300

class AObject {
protected:
    Vector3f position_;
    Vector3f rotation_;

public:

    AObject(void) : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f) {
    }

    virtual void initialize(void) = 0;
    virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
    virtual void draw(void) = 0;
};

#endif
