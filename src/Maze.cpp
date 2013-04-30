/*
 * File:   Maze.cpp
 * Author: floran
 *
 * Created on 30 avril 2013, 19:19
 */

#include "Maze.h"

Maze::Maze(int width, int height) {
    _width = width;
    _height = height;
}

Maze::~Maze() {
}

Maze::getWidth() const {
    return _width;
}

Maze::getHeight() const {
    return _height;
}
