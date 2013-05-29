/*
 * File:   Map.hpp
 * Author: floran
 *
 * Created on 29 mai 2013, 15:08
 */

#ifndef __MAP_HPP__
#define	__MAP_HPP__

#include <GL/gl.h>
#include <GL/glu.h>

#include "Game.hpp"
#include "Model.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Object.hpp"
#include "Input.hpp"

#include <cstdlib>
#include <list>
#include <iostream>
#include <fstream>

#include "AObject.hpp"
#include "Vector3f.hpp"

class Map {
public:
    Map(const char *name, std::list<AObject*> *);
    virtual ~Map();

    int         getMaxX() const;
    void        posMap();
    void        openMap();
private:
    int posX_;
    int posZ_;
    int maxX_;
    const char *name_;
    std::list<AObject*> *objects_;

};

#endif	/* MAP_HPP */

