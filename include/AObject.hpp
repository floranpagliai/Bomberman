#ifndef __AOBJECT__HPP__
#define __AOBJECT__HPP__

#include <GL/gl.h>
#include <GL/glu.h>

#include "AnimStates.hpp"
#include "Assert.hpp"
#include "Clock.hpp"
#include "Color.hpp"
#include "Game.hpp"
#include "GameClock.hpp"
#include "GlError.hpp"
#include "IClock.hpp"
#include "Image.hpp"
#include "Input.hpp"
#include "Model.hpp"
#include "ModelException.hpp"
#include "Resource.hpp"
#include "Text.hpp"
#include "Window.hpp"

#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>

#include "Vector3f.hpp"

#define   BLOCK_SIZE 250

enum eType {
    GROUND = 1,
    WALL,
    CRATE,
    BOMB,
    FLAMME,
    PLAYER

};

class AObject {
protected:
    Vector3f position_;
    Vector3f rotation_;
    bool isOver;
    eType type_;

public:

    AObject(void) : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f), isOver(false) {
    }

    virtual void initialize(void) = 0;
    virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
    virtual void draw(void) = 0;

    Vector3f getPosition(void) const {
        return (this->position_);
    }

    bool getIsOver() const {
        return this->isOver;
    }

    int getType() const {
        return type_;
    }

    bool checkCollision(float x, float z) {
        if (this->position_.x - x - BLOCK_SIZE * 1.25 > 0)
            return false;
        if (this->position_.z - z - BLOCK_SIZE * 1.25 > 0)
            return false;
        if (this->position_.x > x - BLOCK_SIZE * 1.5 || this->position_.x > x + BLOCK_SIZE * 1.25)
            if (this->position_.z > z - BLOCK_SIZE * 1.5 || this->position_.z > z + BLOCK_SIZE * 1.25)
                return true;
        return false;
    }
};

#endif
