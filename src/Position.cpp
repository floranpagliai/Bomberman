/*
 * File:   Position.cpp
 * Author: floran
 *
 * Created on 30 avril 2013, 18:08
 */

#include "Position.h"

Position::Position(int x, int y) {
    _x = x;
    _y = y;
}

Position::~Position() {
}

Position::getX() const {
    return _x;
}

Position::getY() const {
    return _y;
}

