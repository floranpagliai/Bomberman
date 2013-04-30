/*
 * File:   Position.h
 * Author: floran
 *
 * Created on 30 avril 2013, 18:08
 */

#ifndef POSITION_H
#define	POSITION_H

class Position {
public:
    Position();
    virtual ~Position();

    int getX() const;
    int getY() const;

private:
    int _x;
    int _y;

};

#endif	/* POSITION_H */

