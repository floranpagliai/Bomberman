#ifndef __AOBJECT__HPP__
#define __AOBJECT__HPP__

#include <GL/gl.h>
#include <GL/glu.h>

#include <SFML/Audio.hpp>

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
#include <sstream>
#include <iomanip>

#include "Vector3f.hpp"

#define   BLOCK_SIZE 200

enum eType {
    GROUND = 1,
    WALL,
    CRATE,
    BOMB,
    FLAMME,
    BONUS,
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
    //virtual ~AObject(void){}
    virtual void initialize(void) = 0;
    virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
    virtual void draw(void) = 0;

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

    Vector3f getPosition(void) const {
        return (this->position_);
    }

    bool getIsOver(void) const {
        return this->isOver;
    }

    void setIsOver(void) {
        this->isOver = true;
    }

    int getType(void) const {
        return type_;
    }
};

#endif
