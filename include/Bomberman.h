/*
 * File:   Bomberman.h
 * Author: floran
 *
 * Created on 5 juin 2013, 21:09
 */

#ifndef __BOMBERMAN_H__
#define	__BOMBERMAN_H__

#include "Player.h"

class Bomberman : public Player {
private:
    int id_;
public:
    Bomberman(float const, float const, int const, std::list<AObject*> *);
    virtual ~Bomberman();

};

#endif	/* BOMBERMAN_H */

